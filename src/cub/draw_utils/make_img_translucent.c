/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img_translucent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:59:27 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 11:59:39 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	make_img_translucent(t_img *img, double o)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color = get_pixel_img(img, x, y);
			color = ft_mix_color(color, 0xFF000000, o);
			ft_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}
