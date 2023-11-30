/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_map_draw_rays_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:42:39 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 14:42:52 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	init_ray_loop(t_cub *cub, t_rayc *ray)
{
	ray->ray_dx = 0;
	ray->ray_dy = 0;
	ray->x = (double)cub->player_px;
	ray->y = (double)cub->player_py;
	ray->ray = 0;
	ray->ray_proyection = 0;
	ray->anglei = 0;
	ray->angle = 30;
	ray->angle_chunk = 0.046948;
	ray->angle_chunk = ray->angle_chunk * 3;
	ray->last_distance = INT_MAX;
	if (cub->cam_status == OFF)
		ray->chunks = 20;
	else
		ray->chunks = 30;
}

void	init_ray_casting_loop(t_cub *cub, t_rayc *ray)
{
	ray->win = 0;
	ray->winx = cub->player_px;
	ray->winy = cub->player_py;
	ray->ray_a = cub->player_a + ray->anglei - (ray->angle / 2);
	ray->ray_dx = cos(angle_to_radian(get_angle(ray->ray_a)));
	ray->ray_dy = sin(angle_to_radian(get_angle(ray->ray_a)));
	ray->fogxf = cub->player_px + \
	cos(angle_to_radian(get_angle(ray->ray_a))) * ray->chunks;
	ray->fogyf = cub->player_py + \
	sin(angle_to_radian(get_angle(ray->ray_a))) * ray->chunks;
	ray->fog_ds = ft_ds(cub->player_px, ray->fogxf, cub->player_py, ray->fogyf);
	ray->ray_proyection = 0;
	ray->x = cub->player_px + ray->ray_dx * 0;
	ray->y = cub->player_py + ray->ray_dy * 0;
}

void	ray_casting_loop(t_cub *cub, t_rayc *ray)
{
	while (cub->map[(int)ray->y][(int)ray->x] != 1)
	{
		if (cub->map[(int)ray->y][(int)ray->x] == 6 && \
		ray->winx == cub->player_px && ray->winy == cub->player_py)
		{
			ray->win = 1;
			ray->winx = ray->x;
			ray->winy = ray->y;
		}
		ray->x = ray->x + ray->ray_dx * ray->ray_proyection;
		ray->y = ray->y + ray->ray_dy * ray->ray_proyection;
		ray->actual_ds = ft_ds(cub->player_px, ray->x, cub->player_py, ray->y);
		if (ray->actual_ds > ray->fog_ds)
			break ;
		ray->ray_proyection += 0.0001;
	}
}

void	calculate_side_util(t_cub *cub, t_rayc *ray)
{
	float	after_distance;
	float	before_distance;
	float	actual_distance;
	int		after_status;
	int		before_status;

	actual_distance = ft_ds(cub->player_px, ray->x, cub->player_py, ray->y);
	after_status = get_next_status(cub, ray->ray_a, \
	&after_distance, 1, ray->last_distance);
	before_status = get_next_status(cub, ray->ray_a, \
	&before_distance, -1, ray->last_distance);
	before_distance = ft_abs2(before_distance - actual_distance);
	after_distance = ft_abs2(after_distance - actual_distance);
	if (after_distance < before_distance)
		ray->status1 = after_status;
	else
		ray->status1 = before_status;
}
