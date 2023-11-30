/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:02:12 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 13:58:24 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static void	draw_dir_u(t_cub *cub, t_point *point1)
{
	if (cub->minimap_zoom == ZOOM_L || cub->minimap_zoom == ZOOM_S)
	{
		point1->x = 70;
		if (cub->minimap_zoom == ZOOM_S)
			point1->y = 69;
		else
			point1->y = 70;
	}
	else
	{
		point1->x = 75;
		point1->y = 75;
	}
}

void	draw_direction(t_cub *cub)
{
	t_point	point1;
	t_point	point2;
	int		multiplier;

	multiplier = 100;
	draw_dir_u(cub, &point1);
	point1.z = 0;
	point1.color = 0x0000FF00;
	point2.x = point1.x + cub->player_dx * multiplier;
	point2.y = point1.y + cub->player_dy * multiplier;
	point2.z = 0;
	point2.color = 0x0000FF00;
	ft_put_line(point1, point2, cub->minimap);
}
