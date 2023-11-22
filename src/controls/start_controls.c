/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:16:45 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/22 13:15:01 by samusanc         ###   ########.fr       */
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
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	*x = 'O';
	while (i < (int)cub->map_height)
	{
		j = 0;
		while (j < (int)cub->map_width)
		{
			if (cub->map[i][j] == 6)
				cub->map[i][j] = 7;
			j++;
		}
		i++;
	}
	cub->door = 1;
	printf("opening doors\n");
	(void)cub;
}

void	close_doors(t_cub *cub, char *x)
{
	int	i;
	int	j;

	*x = 'C';
	i = 0;
	while (i < (int)cub->map_height)
	{
		j = 0;
		while (j < (int)cub->map_width)
		{
			if (cub->map[i][j] == 7)
				cub->map[i][j] = 6;
			j++;
		}
		i++;
	}
	cub->door = 0;
	printf("closing doors\n");
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

void	move_left(t_cub *cub)
{
	(void)cub;
}
void	move_right(t_cub *cub)
{
	(void)cub;
}
void	move_up(t_cub *cub)
{
	(void)cub;
}
void	move_down(t_cub *cub)
{
	(void)cub;
}

void	put_deltas(t_cub *cub)
{
	cub->player_dx = cos(angle_to_radian(cub->player_a));
	cub->player_dy = sin(angle_to_radian(cub->player_a));
	cub->player_d2x = cos(angle_to_radian(get_angle(cub->player_a + 90)));
	cub->player_d2y = sin(angle_to_radian(get_angle(cub->player_a + 90)));
}

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
	{
		starty -= cub->player_d2y * SPEED;
		startx -= cub->player_d2x * SPEED;
	}
	else if (key == 2)
	{
		starty += cub->player_d2y * SPEED;
		startx += cub->player_d2x * SPEED;
	}
	else if (key == 1)
	{
		starty -= cub->player_dy * SPEED;
		startx -= cub->player_dx * SPEED;
	}
	else if (key == 13)
	{
		starty += cub->player_dy * SPEED;
		startx += cub->player_dx * SPEED;
	}
	finalx = (int)startx;
	finaly = (int)starty;
	if ((finalx >= 0 && finalx < (int)cub->map_width) \
	&& (finaly >= 0 && finaly < (int)cub->map_width ))//this works
	{
		if (cub->map[finaly][finalx] != 1 && cub->map[finaly][finalx] != 6)
		{
			if (cub->map[(int)cub->player_py][(int)cub->player_px] != 8)
				cub->map[(int)cub->player_py][(int)cub->player_px] = 0;
			else
			{
				if (cub->door == 0)
					cub->map[(int)cub->player_py][(int)cub->player_px] = 6;
				else
					cub->map[(int)cub->player_py][(int)cub->player_px] = 7;
			}
			if (cub->map[finaly][finalx] != 6 && cub->map[finaly][finalx] != 7)
				cub->map[finaly][finalx] = 2;
			else
				cub->map[finaly][finalx] = 8;
			cub->player_px = startx;
			cub->player_py = starty;
		}
	}
}

void	increase_dpi(t_cub *cub, int key)
{
	if (key == 18)
		cub->camera_speed = 2;
	else if (key == 19)
		cub->camera_speed = 5;
	else
		cub->camera_speed = 25;
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
		if (key == 123)
			rotate_view_left(cub);
		else
			rotate_view_rigth(cub);
	}
	else if (key == 69 || key == 78)
		minimap_zoom(cub, key);
	else if (key == 18 || key == 19 || key == 20)
		increase_dpi(cub, key);
	else if (key == 10)
	{
		if (!cub->fisheye)
			cub->fisheye = 1;
		else
			cub->fisheye = 0;
	}
	//printf("angle: %d\n", key);
	start_cub(cub);
}

void	frame(void *param)
{
	t_cub		*cub;
	static size_t	i = 0;
	static size_t	j = 0;
	static size_t	k = 0;

	cub = (t_cub *)param;
	//printf("frame:%zu\n", i++);
	if (i % 7 == 0)
	{
		if (j % 7 == 0)
		{
			if (k % 7 == 0)
				start_cub(cub);
			k++;
		}
		j++;
	}
	i++;
}

void	start_controls(t_cub *cub)
{
	mlx_hook(cub->win, 17, 0, (int (*)())close_x, cub);
	mlx_hook(cub->win, 2, 0, (int (*)())key_press, cub);
	mlx_loop_hook(cub->mlx, (int (*)())frame, cub);
	return ;
	(void)cub;
}
