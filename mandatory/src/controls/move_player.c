/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:54:09 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 13:24:38 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static int	calculate_if(t_cub *cub, int finalx, int finaly)
{
	if ((finalx >= 0 && finalx < (int)cub->map_width) \
	&& (finaly >= 0 && finaly < (int)cub->map_width))
		return (1);
	else
		return (0);
}

static void	calculate_door(t_cub *cub)
{
	if (cub->door == 0)
		cub->map[(int)cub->player_py][(int)cub->player_px] = 6;
	else
		cub->map[(int)cub->player_py][(int)cub->player_px] = 7;
}

static void	calculate_next_move(t_cub *cub, float startx, float starty)
{
	int		finalx;
	int		finaly;

	finalx = (int)startx;
	finaly = (int)starty;
	if (calculate_if(cub, finalx, finaly))
	{
		if (cub->map[finaly][finalx] != 1 && cub->map[finaly][finalx] != 6)
		{
			if (cub->map[(int)cub->player_py][(int)cub->player_px] != 8)
				cub->map[(int)cub->player_py][(int)cub->player_px] = 0;
			else
				calculate_door(cub);
			if (cub->map[finaly][finalx] != 6 && cub->map[finaly][finalx] != 7)
				cub->map[finaly][finalx] = 2;
			else
				cub->map[finaly][finalx] = 8;
			cub->player_px = startx;
			cub->player_py = starty;
		}
	}
}

void	move_player(int key, t_cub *cub)
{
	float	startx;
	float	starty;

	startx = cub->player_px;
	starty = cub->player_py;
	if (key == 0)
		move_left(cub, &starty, &startx);
	else if (key == 2)
		move_right(cub, &starty, &startx);
	else if (key == 1)
		move_down(cub, &starty, &startx);
	else if (key == 13)
		move_up(cub, &starty, &startx);
	calculate_next_move(cub, startx, starty);
}
