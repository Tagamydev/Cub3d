/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:16:18 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 22:03:07 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	copy_img_to_img(t_img *src, t_img *dst)
{
	t_cii	ci;

	ci.ii = 0;
	ci.jj = 0;
	while (ci.ii < (size_t)dst->height)
	{
		ci.jj = 0;
		while (ci.jj < (size_t)dst->width)
		{
			ci.multix = (double)(ci.jj * src->width) \
			/ (double)(dst->width);
			ci.multiy = (double)(ci.ii * src->height) \
			/ (double)(dst->height);
			ci.color2 = get_pixel_img(src, ci.multix, ci.multiy);
			ci.color2 = ft_mix_color(ci.color2, 0x0000FF00, 0.35);
			ft_put_pixel(dst, ci.jj, ci.ii, ci.color2);
			ci.jj++;
		}
		ci.ii++;
	}
}

static void	start_cub_sky(t_cub *cub)
{
	if (cub->cam_status == OFF)
		fill_img_sky_n_ground(cub->game, cub->color_sky, cub->color_ground, 0);
	else
		fill_img_sky_n_ground(cub->game, 0x00FF0000, 0x000000FF, 1);
	ft_fill_img(cub->minimap, 0x00000000);
	ray_caster(cub);
	ft_put_sprites(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->game->img, 0, 0);
}

static void	start_cub_cam(t_cub *cub)
{
	ft_fill_img(cub->atm, \
	ft_mix_color(ft_mix_color(cub->color_sky, \
	cub->color_ground, 0.5), 0xFF000000, 0.60));
	if (cub->cam_animation == 0)
	{
		copy_img_to_img(cub->game, cub->miniscreen_s);
		mlx_put_image_to_window(cub->mlx, cub->win, \
		cub->hand->img, 300 + cub->handx, 200 - cub->handy);
		mlx_put_image_to_window(cub->mlx, cub->win, \
		cub->miniscreen_s->img, 314 + cub->handx, 241 - cub->handy);
	}
	else
	{
		copy_img_to_img(cub->game, cub->miniscreen_m);
		mlx_put_image_to_window(cub->mlx, cub->win, \
		cub->hand_m->img, 270, 100);
		mlx_put_image_to_window(cub->mlx, cub->win, \
		cub->miniscreen_m->img, 292, 163);
	}
}

void	start_cub(t_cub *cub)
{
	start_cub_sky(cub);
	if (cub->cam_status == OFF)
		start_cub_cam(cub);
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
}
