/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:08:11 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:08:24 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	draw_cross(t_cub *cub)
{
	t_point	point1;
	t_point	point2;
	float	h;

	h = HEIGHT / 1.3;
	point1.z = 0;
	point2.z = 0;
	point1.color = 0x00FFFFFF;
	point2.color = 0x00FFFFFF;
	point1.x = (WIDTH / 2) - 10;
	point1.y = h / 2;
	point2.x = (WIDTH / 2) + 10;
	point2.y = h / 2;
	ft_put_line(point1, point2, cub->game);
	point1.x = (WIDTH / 2);
	point1.y = (h / 2) - 10;
	point2.x = (WIDTH / 2);
	point2.y = (h / 2) + 10;
	ft_put_line(point1, point2, cub->game);
}
