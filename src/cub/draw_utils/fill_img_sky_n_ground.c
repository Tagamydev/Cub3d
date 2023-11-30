/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img_sky_n_ground.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:00:42 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 13:52:58 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static void	fill_loop3(t_img *img, t_sg *sg)
{
	sg->x = (float)1 / (float)ft_abs(HEIGHT - sg->i);
	sg->m = 0;
	while (sg->i != img->height)
	{
		sg->j = 0;
		while (sg->j != img->width)
		{
			sg->color = ft_mix_color(0, sg->color2, sg->m);
			ft_put_pixel(img, sg->j++, sg->i, sg->color);
		}
		sg->i++;
		sg->m += sg->x;
	}
}

static void	fill_loop2(t_img *img, t_sg *sg)
{
	sg->x = 0;
	while (sg->x != sg->cam - sg->ground)
	{
		sg->color = ft_mix_color(sg->color1, 0, sg->m);
		sg->j = 0;
		while (sg->j != img->width)
		{
			sg->color = ft_mix_color(sg->color1, 0, sg->m);
			ft_put_pixel(img, sg->j, sg->i, 0x0000FF00);
			++sg->j;
		}
		sg->i++;
		sg->x++;
	}
}

static void	fill_loop1(t_img *img, t_sg *sg)
{
	while (sg->i != (img->height / 2 - sg->cam))
	{
		sg->j = 0;
		while (sg->j != img->width)
		{
			sg->color = ft_mix_color(sg->color1, 0, sg->m);
			ft_put_pixel(img, sg->j, sg->i, sg->color);
			++sg->j;
		}
		sg->m += (float)1 / (float)(img->height / 2 - sg->cam);
		sg->i++;
	}
}

static void	fill_init(t_img *img, int status, t_sg *sg)
{
	sg->i = 0;
	sg->j = 0;
	sg->m = 0;
	if (status == OFF)
	{
		sg->cam = 83;
		sg->ground = 12;
	}
	else
	{
		sg->cam = 71;
		sg->ground = 24;
	}
	(void)img;
}

void	fill_img_sky_n_ground(t_img *img, int color1, int color2, int status)
{
	t_sg	sg;

	sg.color1 = color1;
	sg.color2 = color2;
	fill_init(img, status, &sg);
	fill_loop1(img, &sg);
	fill_loop2(img, &sg);
	fill_loop3(img, &sg);
}
