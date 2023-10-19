/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:44:45 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/19 10:54:12 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

static void	ft_rotate_util(t_cub *cub)
{
	cub->camera->alpha = (int)ft_random(cub->random) / 4;
	cub->camera->beta = (int)ft_random(cub->random) / 4;
	cub->camera->gamma = (int)ft_random(cub->random) / 4;
	cub->camera->x_offset = (int)ft_random(cub->random) / 4;
	cub->camera->y_offset = (int)ft_random(cub->random) / 4;
	cub->camera->y_offset -= (int)ft_random(cub->random) / 2;
	cub->camera->y_offset -= 100;
	cub->camera->zoom = (int)(ft_random(cub->random));
	cub->camera->zoom -= (int)((ft_random(cub->random) - \
	ft_random(cub->random)));
}

static void	ft_rotate_util_2(t_cub *cub)
{
	cub->camera->zoom = ft_min((WIDTH / ft_get_lenght("W", cub->map->map) / 2), \
	(HEIGHT / ft_get_lenght("H", cub->map->map) / 2));
	cub->camera->x_offset = 0;
	cub->camera->y_offset = 0;
	cub->camera->alpha = 0;
	cub->camera->beta = 0;
	cub->camera->gamma = -1.5;
}

static void	ft_rotate_util_3(t_cub *cub, int i)
{
	if (i == 1)
	{
		if (cub->angle.projection == CUSTOM)
			cub->angle.angle += 0.05;
		else
			cub->translation += 0.25;
	}
	else if (i == 2)
	{
		if (cub->play)
			cub->play = 0;
		else
			cub->play = 1;
	}
	else
	{
		if (i == 84)
			cub->camera->alpha += 0.1;
		else if (i == 86)
			cub->camera->gamma += 0.05;
		else if (i == 88)
			cub->camera->gamma -= 0.05;
	}
}

static void	ft_rotate_util_4(t_cub *cub, int i)
{
	if (i == 1)
	{
		if (cub->angle.projection == CUSTOM)
			cub->angle.angle -= 0.05;
		else
			cub->translation -= 0.25;
	}
	else
	{
		if (i == 125)
		cub->camera->y_offset += 10;
		if (i == 126)
		cub->camera->y_offset -= 10;
		if (i == 124)
		cub->camera->x_offset += 20;
		if (i == 123)
		cub->camera->x_offset -= 20;
	}
}

int	ft_rotate(int key, t_cub *cub)
{
	if (key == 91)
		cub->camera->alpha -= 0.1;
	else if (key >= 84 && key <= 88)
		ft_rotate_util_3(cub, key);
	else if (key == 15)
		ft_rotate_util(cub);
	else if (key == 29)
		ft_rotate_util_2(cub);
	else if (key == 30)
		ft_rotate_util_3(cub, 1);
	else if (key == 44)
		ft_rotate_util_4(cub, 1);
	else if (key == 69)
		cub->camera->zoom++;
	else if (key == 78)
		cub->camera->zoom--;
	else if (key >= 123 && key <= 126)
		ft_rotate_util_4(cub, key);
	else if (key == 49)
		ft_rotate_util_3(cub, 2);
	ft_ft_draw(cub);
	return (0);
}
