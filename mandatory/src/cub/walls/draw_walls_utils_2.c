/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:20:18 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 20:42:25 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	draw_walls_utlis_3(t_cub *cub, t_ray ray, t_dw *dw)
{
	if (dw->actual_chunk < 0)
		dw->actual_chunk = 0;
	if (dw->actual_chunk > dw->size -1)
		dw->actual_chunk = dw->size - 1;
	(void)cub;
	(void)ray;
}

static void	dw_util_2(t_cub *cub, t_ray ray, t_dw *dw)
{
	dw->size = cub->no_t->size;
	dw->tex = cub->no_t->tex;
	dw->actual_chunk = (get_decimal(ray.x) * (float)dw->size);
}

static void	dw_util_1(t_cub *cub, t_ray ray, t_dw *dw)
{
	dw->size = cub->so_t->size;
	dw->tex = cub->so_t->tex;
	dw->actual_chunk = dw->size - (get_decimal(ray.x) * (float)dw->size);
}

void	draw_walls_utlis_2(t_cub *cub, t_ray ray, t_dw *dw)
{
	if (dw->side == 0x00FF0000)
		dw_util_1(cub, ray, dw);
	else if (dw->side == 0x00FF00FF)
		dw_util_2(cub, ray, dw);
	else if (dw->side == 0xcc)
	{
		dw->size = cub->ea_t->size;
		dw->tex = cub->ea_t->tex;
		dw->actual_chunk = (get_decimal(ray.y) * (float)dw->size);
	}
	else if (dw->side == 0xcc00)
	{
		dw->size = cub->we_t->size;
		dw->tex = cub->we_t->tex;
		dw->actual_chunk = dw->size - (get_decimal(ray.y) * (float)dw->size);
	}
	else
	{
		dw->size = cub->black_t->size;
		dw->tex = cub->black_t->tex;
		dw->actual_chunk = 0;
		dw->fog = 1;
	}
}

void	draw_walls_utlis_1(t_cub *cub, t_ray ray, t_dw *dw, size_t actual_ray)
{
	dw->i = 0;
	dw->fog = 0;
	dw->len = (float)WIDTH / dw->total_rays;
	dw->start_x = dw->len * actual_ray;
	dw->distance = (240 * 15) / ray.distance;
	dw->distance = dw->distance / 5;
	dw->offset_up = ((HEIGHT / 2.5) - dw->distance);
	dw->offset_down = (HEIGHT / 1.25 - dw->offset_up);
	dw->color_ground_mix = 0;
	dw->wall_len = 0;
	(void)cub;
	(void)ray;
}
