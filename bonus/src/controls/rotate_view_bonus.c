/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:52:38 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:52:49 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	rotate_view_left(t_cub *cub)
{
	cub->player_a = get_angle(cub->player_a - cub->camera_speed);
	put_deltas(cub);
	(void)cub;
}

void	rotate_view_rigth(t_cub *cub)
{
	cub->player_a = get_angle(cub->player_a + cub->camera_speed);
	put_deltas(cub);
	(void)cub;
}
