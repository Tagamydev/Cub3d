/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:44:45 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 18:08:20 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

static void	ft_rotate_util(t_fdfc *fdf)
{
	fdf->camera->alpha = (int)ft_random(fdf->random) / 4;
	fdf->camera->beta = (int)ft_random(fdf->random) / 4;
	fdf->camera->gamma = (int)ft_random(fdf->random) / 4;
	fdf->camera->x_offset = (int)ft_random(fdf->random) / 4;
	fdf->camera->y_offset = (int)ft_random(fdf->random) / 4;
	fdf->camera->y_offset -= (int)ft_random(fdf->random) / 2;
	fdf->camera->y_offset -= 100;
	fdf->camera->zoom = (int)(ft_random(fdf->random));
	fdf->camera->zoom -= (int)((ft_random(fdf->random) - \
	ft_random(fdf->random)));
}

static void	ft_rotate_util_2(t_fdfc *fdf)
{
	fdf->camera->zoom = ft_min((WIDTH / ft_get_lenght("W", fdf->map->map) / 2), \
	(HEIGHT / ft_get_lenght("H", fdf->map->map) / 2));
	fdf->camera->x_offset = 0;
	fdf->camera->y_offset = 0;
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = -1.5;
}

static void	ft_rotate_util_3(t_fdfc *fdf, int i)
{
	if (i == 1)
	{
		if (fdf->angle.projection == CUSTOM)
			fdf->angle.angle += 0.05;
		else
			fdf->translation += 0.25;
	}
	else if (i == 2)
	{
		if (fdf->play)
			fdf->play = 0;
		else
			fdf->play = 1;
	}
	else
	{
		if (i == 84)
			fdf->camera->alpha += 0.1;
		else if (i == 86)
			fdf->camera->gamma += 0.05;
		else if (i == 88)
			fdf->camera->gamma -= 0.05;
	}
}

static void	ft_rotate_util_4(t_fdfc *fdf, int i)
{
	if (i == 1)
	{
		if (fdf->angle.projection == CUSTOM)
			fdf->angle.angle -= 0.05;
		else
			fdf->translation -= 0.25;
	}
	else
	{
		if (i == 125)
		fdf->camera->y_offset += 10;
		if (i == 126)
		fdf->camera->y_offset -= 10;
		if (i == 124)
		fdf->camera->x_offset += 20;
		if (i == 123)
		fdf->camera->x_offset -= 20;
	}
}

int	ft_rotate(int key, t_fdfc *fdf)
{
	if (key == 91)
		fdf->camera->alpha -= 0.1;
	else if (key >= 84 && key <= 88)
		ft_rotate_util_3(fdf, key);
	else if (key == 15)
		ft_rotate_util(fdf);
	else if (key == 29)
		ft_rotate_util_2(fdf);
	else if (key == 30)
		ft_rotate_util_3(fdf, 1);
	else if (key == 44)
		ft_rotate_util_4(fdf, 1);
	else if (key == 69)
		fdf->camera->zoom++;
	else if (key == 78)
		fdf->camera->zoom--;
	else if (key >= 123 && key <= 126)
		ft_rotate_util_4(fdf, key);
	else if (key == 49)
		ft_rotate_util_3(fdf, 2);
	ft_ft_draw(fdf);
	return (0);
}
