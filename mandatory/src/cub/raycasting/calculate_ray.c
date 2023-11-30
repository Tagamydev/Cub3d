/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:04:53 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:05:05 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

t_ray	calculate_ray(t_ray tmp_ray, t_cub *cub, int color)
{
	t_ray	result;
	t_p		cam_plane;
	float	shadow;

	result = tmp_ray;
	cam_plane = calculate_cam_plane(result, cub);
	result.distance = sqrt(pow((result.x - cam_plane.x), 2) + \
	pow((result.y - cam_plane.y), 2));
	if (cub->cam_status == OFF)
		shadow = 17;
	else
		shadow = 30;
	shadow = result.distance / shadow;
	if (shadow >= 1)
		shadow = 1;
	result.color = color;
	result.shadow = shadow;
	return (result);
}
