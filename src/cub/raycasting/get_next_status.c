/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:06:35 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:06:48 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	get_next_status(t_cub *cub, float ray_a, float *ds, int m, float last_distance)
{
	double		x;
	double		y;
	double		ray_dx;
	double		ray_dy;
	float		ray_proyection;
	int			status1;

	ray_proyection = 0;
	ray_dx = cos(angle_to_radian(get_angle(ray_a)));
	ray_dy = sin(angle_to_radian(get_angle(ray_a)));
	x = cub->player_px + ray_dx * 0;
	y = cub->player_py + ray_dy * 0;
	while (cub->map[(int)y][(int)x] != 1)
	{
		x = x + ray_dx * ray_proyection;
		y = y + ray_dy * ray_proyection;
		ray_proyection += 0.0001;
	}
	if (ft_abs2(closer_int(y) - y) > ft_abs2(closer_int(x) - x))
		status1 = SIDE;
	else
		status1 = FRONT;
	*ds = ft_ds(cub->player_px, x, cub->player_py, y);
	if (ft_abs2(closer_int(y) - y) < 0.09 && ft_abs2(closer_int(x) - x) < 0.09)
	{
		if (ft_abs2(last_distance - ft_ds(cub->player_px, x, cub->player_py, y) < 1))
			status1 = get_next_status(cub, ray_a + (0.046948 * m), ds, m, *ds);
	}
	return (status1);
}
