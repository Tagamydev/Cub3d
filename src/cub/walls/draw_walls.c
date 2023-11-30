/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:03:15 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 20:20:10 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

t_dwu	dwu_tmp(size_t total_rays, int side, int win)
{
	t_dwu	result;

	result.total_rays = total_rays;
	result.side = side;
	result.win = win;
	return (result);
}
void	draw_walls_utlis_11(t_cub *cub, t_ray ray, t_dw *dw)
{
	dw->i = 0;
	dw->j = 0;
	dw->real_wall_ds = ft_abs(dw->offset_up - dw->offset_down);
	dw->start_point = 0;
	dw->end_point = dw->size;
	if (dw->offset_up < 0)
	{
		dw->start_point = (float)(ft_abs(dw->offset_up) * dw->size) / (float)dw->real_wall_ds;
		if (dw->offset_down > HEIGHT)
			dw->end_point = dw->size - ((float)(ft_abs(dw->offset_down - HEIGHT) * dw->size) / (float)dw->real_wall_ds);
	}
	dw->pixel = ft_abs2(dw->start_point - dw->end_point) / (float)dw->wall_len;
	dw->x = dw->start_point;
	(void)cub;
	(void)ray;
}

void	draw_walls_utlis_13(t_cub *cub, t_ray ray, t_dw *dw)
{
	while (dw->k != dw->len)
	{
		if (dw->i > dw->offset_up && dw->i < dw->offset_down)
		{
			if (!dw->fog)
			{
				if (dw->x < 0 || dw->x >= dw->size)
					dw->x = dw->size - 1;
				ray.color = dw->tex[(int)dw->x][dw->actual_chunk];//here segfault
			}
			if (dw->win)
				ray.color = ft_mix_color(0x000000FF, get_pixel_img(cub->game, dw->j, dw->i), 0.5);
			ray.color = ft_mix_color(ray.color, 0x00000000, ray.shadow);
			ft_put_pixel(cub->game, dw->j, dw->i, ray.color);
			dw->x += dw->pixel;
			if (dw->x > dw->size - 1)
				dw->x = dw->size - 1;
			if (dw->x < 0)
				dw->x = 0;
		}
		dw->k++;
		dw->j++;
	}
}

void	draw_walls_utlis_12(t_cub *cub, t_ray ray, t_dw *dw)
{
	while (dw->i < HEIGHT)
	{
		dw->j = dw->start_x;
		dw->k = 0;
		draw_walls_utlis_13(cub, ray, dw);
		dw->i++;
	}
	(void)cub;
	(void)ray;
}

void	draw_walls_utlis_10(t_cub *cub, t_ray ray, t_dw *dw)
{
	draw_walls_utlis_11(cub, ray, dw);
	draw_walls_utlis_12(cub, ray, dw);
}

void	draw_walls_utlis_9(t_cub *cub, t_ray ray, t_dw *dw)
{
	if (cub->cam_status == OFF)
		draw_walls_utlis_10(cub, ray, dw);
}

void	draw_walls(t_cub *cub, t_ray ray, size_t actual_ray, t_dwu du)
{
	t_dw dw;

	dw.side = du.side;
	dw.win = du.win;
	dw.total_rays = du.total_rays;
	draw_walls_utlis_1(cub, ray, &dw, actual_ray);
	draw_walls_utlis_2(cub, ray, &dw);
	draw_walls_utlis_3(cub, ray, &dw);
	draw_walls_utlis_4(cub, ray, &dw);
	draw_walls_utlis_9(cub, ray, &dw);
	draw_walls_utlis_9(cub, ray, &dw);
}
