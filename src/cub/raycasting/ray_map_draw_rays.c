/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_map_draw_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:07:11 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 14:20:31 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	ray_map_draw_rays(t_cub *cub)
{
	t_rayc	ray;

	//						init_ray_loop
	//=============================================================================================//
	ray.ray_dx = 0;
	ray.ray_dy = 0;
	ray.x = (double)cub->player_px;
	ray.y = (double)cub->player_py;
	ray.ray = 0;
	ray.ray_proyection = 0;
	ray.anglei = 0;
	ray.angle = 30;
	ray.angle_chunk = 0.046948;
	ray.angle_chunk = ray.angle_chunk * 3;
	ray.last_distance = INT_MAX;
	if (cub->cam_status == OFF)
		ray.chunks = 20;
	else
		ray.chunks = 30;
	//						ray_loop
	//=============================================================================================//
	while (ray.ray < WIDTH / 3)
	{
		//						init_ray_casting_loop
		//=============================================================================================//
		ray.win = 0;
		ray.winx = cub->player_px;
		ray.winy = cub->player_py;
		ray.ray_a = cub->player_a + ray.anglei - (ray.angle / 2);
		ray.ray_dx = cos(angle_to_radian(get_angle(ray.ray_a)));
		ray.ray_dy = sin(angle_to_radian(get_angle(ray.ray_a)));
		ray.fogxf = cub->player_px + cos(angle_to_radian(get_angle(ray.ray_a))) * ray.chunks;
		ray.fogyf = cub->player_py + sin(angle_to_radian(get_angle(ray.ray_a))) * ray.chunks;
		ray.fog_ds = ft_ds(cub->player_px, ray.fogxf, cub->player_py, ray.fogyf);
		ray.ray_proyection = 0;
		ray.x = cub->player_px + ray.ray_dx * 0;
		ray.y = cub->player_py + ray.ray_dy * 0;
		//						ray_casting_loop
		//=============================================================================================//
		while (cub->map[(int)ray.y][(int)ray.x] != 1)
		{
			if (cub->map[(int)ray.y][(int)ray.x] == 6 && ray.winx == cub->player_px && ray.winy == cub->player_py)
			{
				ray.win = 1;
				ray.winx = ray.x;
				ray.winy = ray.y;
			}
			ray.x = ray.x + ray.ray_dx * ray.ray_proyection;
			ray.y = ray.y + ray.ray_dy * ray.ray_proyection;
			ray.actual_ds = ft_ds(cub->player_px, ray.x, cub->player_py, ray.y);
			if (ray.actual_ds > ray.fog_ds)
				break;
			ray.ray_proyection += 0.0001;
		}
		//						calculate_side
		//=============================================================================================//
		if (ray.actual_ds < ray.fog_ds)
		{
			if (ft_abs2(closer_int(ray.y) - ray.y) > ft_abs2(closer_int(ray.x) - ray.x))
				ray.status1 = SIDE;
			else
				ray.status1 = FRONT;
			if (ft_abs2(closer_int(ray.y) - ray.y) < 0.09 && ft_abs2(closer_int(ray.x) - ray.x) < 0.09)
			{
				if (ft_abs2(ray.last_distance - ft_ds(cub->player_px, ray.x, cub->player_py, ray.y) < 1))
				{
				//==============================================================================//
					float	after_distance;
					float	before_distance;
					float	actual_distance;
					int		after_status;
					int		before_status;
	
					actual_distance = ft_ds(cub->player_px, ray.x, cub->player_py, ray.y);
					after_status = get_next_status(cub, ray.ray_a, &after_distance, 1, ray.last_distance);
					before_status = get_next_status(cub, ray.ray_a, &before_distance, -1, ray.last_distance);
					before_distance = ft_abs2(before_distance - actual_distance);
					after_distance = ft_abs2(after_distance - actual_distance);
					if (after_distance < before_distance)
						ray.status1 = after_status;
					else
						ray.status1 = before_status;
				//==============================================================================//
				}
				else
					ray.status1 = 4;
			}
		}
		else
			ray.status1 = 5;
		//						put_side
		//=============================================================================================//
		if (ray.status1 == SIDE)
		{
			if (get_angle(ray.ray_a) < 270 && get_angle(ray.ray_a) > 90)
				ray.color2 = 0x0000FF00;
			else
				ray.color2 = 0x000000FF;
			ray.color2 = ft_mix_color(ray.color2, 0x00000000, 0.2);
		}
		else if (ray.status1 == FRONT)
		{
			if (get_angle(ray.ray_a) < 180 && get_angle(ray.ray_a) > 0)
				ray.color2 = 0x00FF0000;
			else
				ray.color2 = 0x00ff00ff;
		}
		else if (ray.status1 == 4)
				ray.color2 = 0;
		else
				ray.color2 = ft_mix_color(cub->color_sky, 0, 0.10);
		//=============================================================================================//
		ray.last_distance = ft_ds(cub->player_px, ray.x, cub->player_py, ray.y);
		draw_walls(cub, calculate_ray(make_tmp_ray(ray.x, ray.y, ray.ray_a, cub), cub, ray.color2), ray.ray, WIDTH / 3, ray.color2, 0);
		if (ray.win == 1)
			draw_walls(cub, \
			calculate_ray(make_tmp_ray(ray.winx, ray.winy, ray.ray_a, cub), \
			cub, ray.color2), ray.ray, WIDTH / 3, ray.color2, 1);
		//=============================================================================================//
		ray.anglei += ray.angle_chunk;
		ray.ray++;
	}
	(void)cub;
}
