/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_map_draw_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:07:11 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:07:25 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	ray_map_draw_rays(t_cub *cub)
{
	static int	last_status = SIDE;
	double		x;
	double		y;
	double		anglei;
	double		ray_dx;
	double		ray_dy;
	double		angle_chunk;
	double		last_distance;
	float		fogxf;
	float		fogyf;
	float		fog_ds;
	float		actual_ds;
	float		winx;
	float		winy;
	float		ray_a;
	float		ray_proyection;
	int			ray;
	int			angle;
	int			color2;
	int			status1;
	int			chunks;
	int			win;

	//=============================================================================================//
	ray_dx = 0;
	ray_dy = 0;
	x = (double)cub->player_px;
	y = (double)cub->player_py;
	ray = 0;
	ray_proyection = 0;
	anglei = 0;
	angle = 30;
	angle_chunk = 0.046948;
	angle_chunk = angle_chunk * 3;
	last_distance = INT_MAX;
	if (cub->cam_status == OFF)
		chunks = 20;
	else
		chunks = 30;
	//=============================================================================================//
	while (ray < WIDTH / 3)
	{
		//=============================================================================================//
		win = 0;
		winx = cub->player_px;
		winy = cub->player_py;
		ray_a = cub->player_a + anglei - (angle / 2);
		ray_dx = cos(angle_to_radian(get_angle(ray_a)));
		ray_dy = sin(angle_to_radian(get_angle(ray_a)));
		fogxf = cub->player_px + cos(angle_to_radian(get_angle(ray_a))) * chunks;
		fogyf = cub->player_py + sin(angle_to_radian(get_angle(ray_a))) * chunks;
		fog_ds = ft_ds(cub->player_px, fogxf, cub->player_py, fogyf);
		ray_proyection = 0;
		x = cub->player_px + ray_dx * 0;
		y = cub->player_py + ray_dy * 0;
		//=============================================================================================//
		while (cub->map[(int)y][(int)x] != 1)
		{
			if (cub->map[(int)y][(int)x] == 6 && winx == cub->player_px && winy == cub->player_py)
			{
				win = 1;
				winx = x;
				winy = y;
			}
			x = x + ray_dx * ray_proyection;
			y = y + ray_dy * ray_proyection;
			actual_ds = ft_ds(cub->player_px, x, cub->player_py, y);
			if (actual_ds > fog_ds)
				break;
			ray_proyection += 0.0001;
		}
		//=============================================================================================//
		if (actual_ds < fog_ds)
		{
			if (ft_abs2(closer_int(y) - y) > ft_abs2(closer_int(x) - x))
				status1 = SIDE;
			else
				status1 = FRONT;
			if (ft_abs2(closer_int(y) - y) < 0.09 && ft_abs2(closer_int(x) - x) < 0.09)
			{
				if (ft_abs2(last_distance - ft_ds(cub->player_px, x, cub->player_py, y) < 1))
				{
				//==============================================================================//
					float	after_distance;
					float	before_distance;
					float	actual_distance;
					int		after_status;
					int		before_status;
	
					actual_distance = ft_ds(cub->player_px, x, cub->player_py, y);
					after_status = get_next_status(cub, ray_a, &after_distance, 1, last_distance);
					before_status = get_next_status(cub, ray_a, &before_distance, -1, last_distance);
					before_distance = ft_abs2(before_distance - actual_distance);
					after_distance = ft_abs2(after_distance - actual_distance);
					if (after_distance < before_distance)
						status1 = after_status;
					else
						status1 = before_status;
				//==============================================================================//
				}
				else
					status1 = 4;
			}
		}
		else
			status1 = 5;
		last_status = status1;
		//=============================================================================================//
		if (status1 == SIDE)
		{
			if (get_angle(ray_a) < 270 && get_angle(ray_a) > 90)
				color2 = 0x0000FF00;//draw rays in minimap
			else
				color2 = 0x000000FF;//draw rays in minimap
			color2 = ft_mix_color(color2, 0x00000000, 0.2);
		}
		else if (status1 == FRONT)
		{
			if (get_angle(ray_a) < 180 && get_angle(ray_a) > 0)
				color2 = 0x00FF0000;//draw rays in minimap
			else
				color2 = 0x00ff00ff;//draw rays in minimap
		}
		else if (status1 == 4)
				color2 = 0;//draw rays in minimap
		else
				color2 = ft_mix_color(cub->color_sky, 0, 0.10);
		//=============================================================================================//
		last_distance = ft_ds(cub->player_px, x, cub->player_py, y);
		draw_walls(cub, calculate_ray(make_tmp_ray(x, y, ray_a, cub), cub, color2), ray, WIDTH / 3, color2, 0);
		if (win == 1)
			draw_walls(cub, \
			calculate_ray(make_tmp_ray(winx, winy, ray_a, cub), \
			cub, color2), ray, WIDTH / 3, color2, 1);
		//=============================================================================================//
		anglei += angle_chunk;
		ray++;
	}
	(void)cub;
}
