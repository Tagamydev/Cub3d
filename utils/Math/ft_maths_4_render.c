/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths_4_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:24:51 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 18:28:23 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	ft_make_maths(t_point *point, t_fdfc *fdf)
{
	if (point->z != 0)
		point->z *= fdf->translation;
	point->x *= fdf->camera->zoom;
	point->y *= fdf->camera->zoom;
	point->z *= fdf->camera->zoom / fdf->camera->z_divisor;
	point->x -= (fdf->map->width * fdf->camera->zoom) / 2;
	point->y -= (fdf->map->height * fdf->camera->zoom) / 2;
	ft_rotate_x(&point->y, &point->z, fdf->camera->alpha);
	ft_rotate_y(&point->x, &point->z, fdf->camera->beta);
	ft_rotate_z(&point->x, &point->y, fdf->camera->gamma);
	if (fdf->angle.projection == ISO || \
		fdf->angle.projection == ISO_GAMES || \
		fdf->angle.projection == CONIC || \
		fdf->angle.projection == CUSTOM)
		ft_iso(&point->x, &point->y, point->z, fdf);
	point->x += (WIDTH) / 2 + fdf->camera->x_offset;
	point->y += (HEIGHT + fdf->map->height * fdf->camera->zoom) \
	/ 2 + fdf->camera->y_offset;
}
