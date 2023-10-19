/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:41:54 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/19 10:53:22 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	ft_close(void *param)
{
	(void)param;
	exit(0);
}

void	ft_change_proyection(t_cub *cub)
{
	if (cub->angle.projection == CONIC)
		cub->angle.projection = ISO;
	else
		cub->angle.projection++;
	if (cub->angle.projection == PARALLEL)
	{
		cub->camera->alpha = 0;
		cub->camera->beta = 0;
		cub->camera->gamma = 1.55;
	}
	ft_ft_draw(cub);
}

int	ft_key_press(int key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
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
		ft_rotate(key, cub);
	if (key == 87)
		ft_change_proyection(cub);
	return (0);
}

void	ft_counter(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	cub->random += 1;
	if (cub->play)
	{
		cub->camera->gamma += 0.01;
		ft_ft_draw(cub);
	}
}
