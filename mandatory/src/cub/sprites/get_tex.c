/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:10:32 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 19:06:39 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static void	get_tex_second_timer(t_cub *cub, t_spr *tmp)
{
	float	slow;

	slow = 0.6;
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

static void	get_tex_timer(t_cub *cub, t_spr *tmp)
{
	float	slow;

	slow = 0.6;
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

t_tex	*get_tex(t_cub *cub, t_spr *tmp)
{
	float	slow;
	t_tex	*result;

	slow = 0.6;
	if (cub->frame >= tmp->next_frame)
		get_tex_timer(cub, tmp);
	if (cub->cam_status == ON)
	{
		if (cub->frame >= tmp->next_blink)
			get_tex_second_timer(cub, tmp);
		result = cub->t_nina_cam[tmp->blink][tmp->frame];
	}
	else
		result = cub->t_nina_ncam[tmp->frame];
	return (result);
}
