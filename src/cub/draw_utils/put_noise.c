/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_noise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:09:02 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:09:13 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	put_noise(t_cub *cub)
{
	static int last_noise = 0;
	int	noise;

	noise = ft_random(1, 1, 7);
	while (noise == last_noise)
		noise = ft_random(1, 1, 7);
	last_noise = noise;
	if (noise == 1)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->noise1->img, 0, 0);
	else if (noise == 2)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->noise2->img, 0, 0);
	else if (noise == 3)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->noise3->img, 0, 0);
	else if (noise == 4)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->noise4->img, 0, 0);
	else if (noise == 5)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->noise5->img, 0, 0);
	else
		mlx_put_image_to_window(cub->mlx, cub->win, cub->noise6->img, 0, 0);
}
