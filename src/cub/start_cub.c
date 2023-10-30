/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:16:18 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/30 12:27:46 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	fill_img_sky_n_ground(t_img *img, int color1, int color2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != (img->height / 2))
	{
		j = 0;
		while (j != img->width)
		{
			ft_put_pixel(img, j, i, color1);
			++j;
		}
		i++;
	}
	while (i != img->height)
	{
		j = 0;
		while (j != img->width)
		{
			ft_put_pixel(img, j, i, color2);
			++j;
		}
		i++;
	}
}

void	start_cub(t_cub *cub)
{
	fill_img_sky_n_ground(cub->game, cub->color_ground, cub->color_sky);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->game->img, 0, 0);
	return ;
	(void)cub;
}
