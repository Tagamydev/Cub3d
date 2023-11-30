/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:16:18 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:11:35 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	start_cub(t_cub *cub)
{
	if (cub->cam_status == OFF)
		fill_img_sky_n_ground(cub->game, cub->color_sky, cub->color_ground, 0);
	else
		fill_img_sky_n_ground(cub->game, 0x00FF0000, 0x000000FF, 1);
	ft_fill_img(cub->minimap, 0x00000000);
	ray_caster(cub);
	ft_put_sprites(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->game->img, 0, 0);
	if (cub->cam_status == OFF)
	{
		ft_fill_img(cub->atm, \
		ft_mix_color(ft_mix_color(cub->color_sky, \
		cub->color_ground, 0.5), 0xFF000000, 0.60));
		if (cub->cam_animation == 0)
			mlx_put_image_to_window(cub->mlx, cub->win, cub->hand->img, 300 + cub->handx, 200 - cub->handy);
		else
			mlx_put_image_to_window(cub->mlx, cub->win, cub->hand_m->img, 270, 100);
	}
	else
		ft_fill_img(cub->atm, ft_mix_color(0x0000FF00, 0xFF000000, 0.4));

	mlx_put_image_to_window(cub->mlx, cub->win, cub->atm->img, 0, 0);

	if (cub->door == 1)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->hud_o->img, 0, 0);
	else
		mlx_put_image_to_window(cub->mlx, cub->win, cub->hud_c->img, 0, 0);

	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 13, 8);


	put_noise(cub);
	return ;
	(void)cub;
}
