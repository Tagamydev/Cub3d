/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_to_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:05:43 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:05:56 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

t_p	ray_to_point(t_ray ray)
{
	t_p	result;

	result.x = ray.x;
	result.y = ray.y;
	result.dx = cos(angle_to_radian(get_angle(ray.angle))) * 3;
	result.dy = sin(angle_to_radian(get_angle(ray.angle))) * 3;
	return (result);
}
