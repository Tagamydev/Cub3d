/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_open_noise.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:18:33 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/30 20:18:50 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	cub_open_utils_noise_util(t_cub *cub)
{
	make_img_translucent(cub->noise1, 0.6);
	make_img_translucent(cub->noise2, 0.6);
	make_img_translucent(cub->noise3, 0.6);
	make_img_translucent(cub->noise4, 0.6);
	make_img_translucent(cub->noise5, 0.6);
	make_img_translucent(cub->noise6, 0.6);
}

int	cub_open_utils_noise(t_cub *cub)
{
	cub->noise1 = ft_open_img(cub->mlx, "./src/img/noise1.xpm");
	if (!cub->noise1)
		return (0);
	cub->noise2 = ft_open_img(cub->mlx, "./src/img/noise2.xpm");
	if (!cub->noise2)
		return (0);
	cub->noise3 = ft_open_img(cub->mlx, "./src/img/noise3.xpm");
	if (!cub->noise3)
		return (0);
	cub->noise4 = ft_open_img(cub->mlx, "./src/img/noise4.xpm");
	if (!cub->noise4)
		return (0);
	cub->noise5 = ft_open_img(cub->mlx, "./src/img/noise5.xpm");
	if (!cub->noise5)
		return (0);
	cub->noise6 = ft_open_img(cub->mlx, "./src/img/noise6.xpm");
	if (!cub->noise6)
		return (0);
	cub_open_utils_noise_util(cub);
	return (1);
}

int	cub_open_utils(t_cub *cub)
{
	cub->hud_o = ft_open_img(cub->mlx, "./src/img/hud_o.xpm");
	if (!cub->hud_o)
		return (0);
	cub->hud_c = ft_open_img(cub->mlx, "./src/img/hud_c.xpm");
	if (!cub->hud_c)
		return (0);
	cub->hand = ft_open_img(cub->mlx, "./src/img/hand.xpm");
	if (!cub->hand)
		return (0);
	cub->hand_m = ft_open_img(cub->mlx, "./src/img/hand_m.xpm");
	if (!cub->hand_m)
		return (0);
	if (!cub_open_utils_noise(cub))
		return (0);
	return (1);
}
