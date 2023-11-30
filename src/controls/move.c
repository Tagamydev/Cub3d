/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:51:43 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 13:07:32 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	move_left(t_cub *cub, float *starty, float *startx)
{
	hand_loop(cub);
	*starty -= cub->player_d2y * SPEED;
	*startx -= cub->player_d2x * SPEED;
}

void	move_right(t_cub *cub, float *starty, float *startx)
{
	hand_loop(cub);
	*starty += cub->player_d2y * SPEED;
	*startx += cub->player_d2x * SPEED;
}

void	move_up(t_cub *cub, float *starty, float *startx)
{
	hand_loop(cub);
	*starty += cub->player_dy * SPEED;
	*startx += cub->player_dx * SPEED;
}

void	move_down(t_cub *cub, float *starty, float *startx)
{
	hand_loop(cub);
	*starty -= cub->player_dy * SPEED;
	*startx -= cub->player_dx * SPEED;
}
