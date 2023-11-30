/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:57:14 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 13:06:34 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static void	inseption_lvl3(t_cub *cub)
{
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
	cub->frame += 1;
	start_cub(cub);
}

static void	inseption_lvl2(t_cub *cub)
{
	static size_t	k = 0;

	if (cub->cam_animation == 1)
		cub->cam_animation = 2;
	else if (cub->cam_animation == 2)
	{
		cub->cam_animation = 1;
		if (cub->cam_status == OFF)
			cub->cam_status = ON;
		else
			cub->cam_status = OFF;
		start_cub(cub);
		cub->cam_animation = 0;
	}
	if (k % 7 == 0)
		inseption_lvl3(cub);
	k++;
}

static void	inseption_lvl1(t_cub *cub)
{
	static size_t	j = 0;

	if (j % 7 == 0)
		inseption_lvl2(cub);
	j++;
}

void	frame(void *param)
{
	static size_t	i = 0;
	t_cub			*cub;

	cub = (t_cub *)param;
	if (i % 7 == 0)
		inseption_lvl1(cub);
	i++;
}
