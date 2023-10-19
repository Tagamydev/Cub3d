/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths_4_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:24:51 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/19 10:48:44 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	ft_make_maths(t_point *point, t_cub *cub)
{
	if (point->z != 0)
		point->z *= cub->translation;
	point->x *= cub->camera->zoom;
	point->y *= cub->camera->zoom;
	point->z *= cub->camera->zoom / cub->camera->z_divisor;
	point->x -= (cub->map->width * cub->camera->zoom) / 2;
	point->y -= (cub->map->height * cub->camera->zoom) / 2;
	ft_rotate_x(&point->y, &point->z, cub->camera->alpha);
	ft_rotate_y(&point->x, &point->z, cub->camera->beta);
	ft_rotate_z(&point->x, &point->y, cub->camera->gamma);
	if (cub->angle.projection == ISO || \
		cub->angle.projection == ISO_GAMES || \
		cub->angle.projection == CONIC || \
		cub->angle.projection == CUSTOM)
		ft_iso(&point->x, &point->y, point->z, cub);
	point->x += (WIDTH) / 2 + cub->camera->x_offset;
	point->y += (HEIGHT + cub->map->height * cub->camera->zoom) \
	/ 2 + cub->camera->y_offset;
}
