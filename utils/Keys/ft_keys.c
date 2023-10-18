/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:41:54 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 18:26:21 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	ft_close(void *param)
{
	(void)param;
	exit(0);
}

void	ft_change_proyection(t_fdfc *fdf)
{
	if (fdf->angle.projection == CONIC)
		fdf->angle.projection = ISO;
	else
		fdf->angle.projection++;
	if (fdf->angle.projection == PARALLEL)
	{
		fdf->camera->alpha = 0;
		fdf->camera->beta = 0;
		fdf->camera->gamma = 1.55;
	}
	ft_ft_draw(fdf);
}

int	ft_key_press(int key, void *param)
{
	t_fdfc	*fdf;

	fdf = (t_fdfc *)param;
	if (key == 53)
		ft_close(param);
	if (key == 91 || key == 86 \
		|| key == 84 || key == 88 \
		|| key == 15 || key == 29 \
		|| key == 30 || key == 44 \
		|| key == 69 || key == 78 \
		|| key == 49 || key == 98 \
		|| key == 123 || key == 124 \
		|| key == 126 || key == 125)
		ft_rotate(key, fdf);
	if (key == 87)
		ft_change_proyection(fdf);
	return (0);
}

void	ft_counter(void *param)
{
	t_fdfc	*fdf;

	fdf = (t_fdfc *)param;
	fdf->random += 1;
	if (fdf->play)
	{
		fdf->camera->gamma += 0.01;
		ft_ft_draw(fdf);
	}
}
