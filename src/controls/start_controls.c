/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:16:45 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/31 14:29:51 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	close_x(void *param)
{
	(void)param;
	exit(1);
	return ;
}

void	open_doors(t_cub *cub, char *x)
{
	*x = 'O';
	printf("opening the doors\n");
	(void)cub;
}

void	close_doors(t_cub *cub, char *x)
{
	*x = 'C';
	printf("closing the doors\n");
	(void)cub;
}

void	minimap_zoom(t_cub *cub, int key)
{
	if (key == 69)
	{
		if (cub->minimap_zoom == ZOOM_M)
			cub->minimap_zoom = ZOOM_L;
		else if (cub->minimap_zoom == ZOOM_S)
			cub->minimap_zoom = ZOOM_M;
	}
	else
	{
		if (cub->minimap_zoom == ZOOM_M)
			cub->minimap_zoom = ZOOM_S;
		else if (cub->minimap_zoom == ZOOM_L)
			cub->minimap_zoom = ZOOM_M;
	}
}

void	move_player(int key, t_cub *cub)
{
	int	finalx;
	int	finaly;
	float	startx;
	float	starty;

	// this code maybe will change later
	startx = cub->player_px;
	starty = cub->player_py;
	if (key == 0)
		startx -= SPEED;
	else if (key == 2)
		startx += SPEED;
	else if (key == 1)
		starty += SPEED;
	else if (key == 13)
		starty -= SPEED;
	finalx = (int)startx;
	finaly = (int)starty;
	if ((finalx >= 0 && finalx < (int)cub->map_width) \
	&& (finaly >= 0 && finaly < (int)cub->map_width ))//this works
	{
		if (cub->map[finaly][finalx] != 1)
		{
			if (cub->map[(int)cub->player_py][(int)cub->player_px] != 8)
				cub->map[(int)cub->player_py][(int)cub->player_px] = 0;
			else
				cub->map[(int)cub->player_py][(int)cub->player_px] = 6;
			if (cub->map[finaly][finalx] != 6 && cub->map[finaly][finalx] != 7)
				cub->map[finaly][finalx] = 2;
			else
				cub->map[finaly][finalx] = 8;
			cub->player_px = startx;
			cub->player_py = starty;
		}
	}
}

void	key_press(int key, void *param)
{
	static char	door = 'C';
	t_cub		*cub;

	cub = (t_cub *)param;
	if (key == 53)
		close_x(param);
	else if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		move_player(key, cub);
	}
	else if (key == 49)
	{
		if (door == 'C')
			open_doors(cub, &door);
		else
			close_doors(cub, &door);
	}
	else if (key == 123 || key == 124)
	{
		;
	}
	else if (key == 69 || key == 78)
		minimap_zoom(cub, key);
	printf("key: %d\n", key);
	start_cub(cub);
}

void	start_controls(t_cub *cub)
{
	mlx_hook(cub->win, 17, 0, (int (*)())close_x, cub);
	mlx_hook(cub->win, 2, 0, (int (*)())key_press, cub);
	return ;
	(void)cub;
}
