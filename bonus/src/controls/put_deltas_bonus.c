/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_deltas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:52:12 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:52:23 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	put_deltas(t_cub *cub)
{
	cub->player_dx = cos(angle_to_radian(cub->player_a));
	cub->player_dy = sin(angle_to_radian(cub->player_a));
	cub->player_d2x = cos(angle_to_radian(get_angle(cub->player_a + 90)));
	cub->player_d2y = sin(angle_to_radian(get_angle(cub->player_a + 90)));
}
