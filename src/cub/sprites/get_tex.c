/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:10:32 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 18:26:55 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

t_tex	*get_tex(t_cub *cub, t_spr *tmp)
{
	float	slow;
	t_tex	*result;

	slow = 0.6;
	if (cub->frame >= tmp->next_frame)
	{
		if (tmp->frame < 4)
		{
			tmp->frame += 1;
			tmp->next_frame = cub->frame + (10 * slow);
		}
		else
		{
			tmp->frame = 0;
			tmp->next_frame = cub->frame + (10 * slow);
		}
	}
	if (cub->cam_status == ON)
	{
		if (cub->frame >= tmp->next_blink)
		{
			if (tmp->blink != 2)
			{
				tmp->blink += 1;
				tmp->next_blink = cub->frame + 1 * slow;
			}
			else
			{
				tmp->blink = 0;
				tmp->next_blink = cub->frame + ft_random(1, 10 * slow, 100 * slow);
			}
		}
		result = cub->t_nina_cam[tmp->blink][tmp->frame];
	}
	else
		result = cub->t_nina_ncam[tmp->frame];
	return (result);
}
