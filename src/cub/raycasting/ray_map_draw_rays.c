/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_map_draw_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:07:11 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 14:42:32 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	calculate_side(t_cub *cub, t_rayc *ray)
{
	if (ray->actual_ds < ray->fog_ds)
	{
		if (ft_abs2(closer_int(ray->y) - ray->y) > \
			ft_abs2(closer_int(ray->x) - ray->x))
			ray->status1 = SIDE;
		else
			ray->status1 = FRONT;
		if (ft_abs2(closer_int(ray->y) - ray->y) \
			< 0.09 && ft_abs2(closer_int(ray->x) - ray->x) < 0.09)
		{
			if (ft_abs2(ray->last_distance - ft_ds(cub->player_px, \
			ray->x, cub->player_py, ray->y) < 1))
				calculate_side_util(cub, ray);
			else
				ray->status1 = 4;
		}
	}
	else
		ray->status1 = 5;
}

void	put_side(t_cub *cub, t_rayc *ray)
{
	if (ray->status1 == SIDE)
	{
		if (get_angle(ray->ray_a) < 270 && get_angle(ray->ray_a) > 90)
			ray->color2 = 0x0000FF00;
		else
			ray->color2 = 0x000000FF;
		ray->color2 = ft_mix_color(ray->color2, 0x00000000, 0.2);
	}
	else if (ray->status1 == FRONT)
	{
		if (get_angle(ray->ray_a) < 180 && get_angle(ray->ray_a) > 0)
			ray->color2 = 0x00FF0000;
		else
			ray->color2 = 0x00ff00ff;
	}
	else if (ray->status1 == 4)
		ray->color2 = 0;
	else
		ray->color2 = ft_mix_color(cub->color_sky, 0, 0.10);
}

void	ray_loop(t_cub *cub, t_rayc *ray)
{
	while (ray->ray < WIDTH / 3)
	{
		init_ray_casting_loop(cub, ray);
		ray_casting_loop(cub, ray);
		calculate_side(cub, ray);
		put_side(cub, ray);
		ray->last_distance = ft_ds(cub->player_px, ray->x, \
		cub->player_py, ray->y);
		draw_walls(cub, calculate_ray(make_tmp_ray(ray->x, \
		ray->y, ray->ray_a, cub), \
		cub, ray->color2), ray->ray, WIDTH / 3, ray->color2, 0);
		if (ray->win == 1)
			draw_walls(cub, \
			calculate_ray(make_tmp_ray(ray->winx, ray->winy, ray->ray_a, cub), \
			cub, ray->color2), ray->ray, WIDTH / 3, ray->color2, 1);
		ray->anglei += ray->angle_chunk;
		ray->ray++;
	}
}

void	ray_map_draw_rays(t_cub *cub)
{
	t_rayc	ray;

	init_ray_loop(cub, &ray);
	ray_loop(cub, &ray);
	(void)cub;
}
