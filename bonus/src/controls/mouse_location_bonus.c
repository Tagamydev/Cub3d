/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_location.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:00:54 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 13:07:13 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	mouse_location(int x, int y, void *param)
{
	t_cub		*cub;
	int			v;

	cub = (t_cub *)param;
	v = cub->camera_speed;
	cub->camera_speed = 1;
	if ((cub->mousex >= 15 && cub->mousey <= 624) && \
		(cub->mousey >= 11 && cub->mousey <= 375))
	{
		if (cub->mouse_press == 1)
		{
			if (cub->mousex < 320)
				rotate_view_left(cub);
			else
				rotate_view_rigth(cub);
		}
	}
	cub->camera_speed = v;
	cub->mousex = x;
	cub->mousey = y;
}
