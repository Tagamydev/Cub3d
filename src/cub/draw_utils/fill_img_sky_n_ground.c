/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img_sky_n_ground.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:00:42 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:00:54 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	fill_img_sky_n_ground(t_img *img, int color1, int color2, int status)
{
	int	i;
	int	j;
	float	m;
	int	color;
	float x;

	i = 0;
	j = 0;
	m = 0;
	int cam;
	int ground;
	if (status == OFF)
	{
		cam = 83;
		ground = 12;
	}
	else
	{
		cam = 71;
		ground = 24;
	}
	while (i != (img->height / 2 - cam))
	{
		j = 0;
		while (j != img->width)
		{
			color = ft_mix_color(color1, 0, m);
			ft_put_pixel(img, j, i, color);
			++j;
		}
		m += (float)1 / (float)(img->height / 2 - cam);
		i++;
	}
	x = 0;
	while (x != cam - ground)
	{
		color = ft_mix_color(color1, 0, m);
		j = 0;
		while (j != img->width)
		{
			color = ft_mix_color(color1, 0, m);
			ft_put_pixel(img, j, i, 0x0000FF00);
			++j;
		}
		i++;
		x++;
	}
	x = (float)1 / (float)ft_abs(HEIGHT - i);
	m = 0;
	while (i != img->height)
	{
		j = 0;
		while (j != img->width)
		{
			color = ft_mix_color(0, color2, m);
			ft_put_pixel(img, j++, i, color);
		}
		i++;
		m += x;
	}
}
