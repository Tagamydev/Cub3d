/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_funtions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:36:48 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 18:33:03 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx_funtions.h>

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img->width && \
	y < img->height && y < HEIGHT && x < WIDTH)
	{
		dst = img->data_addr + ((y * img->line_size) + \
		((x * (img->bits_per_pixel / 8))));
		*(unsigned int *)dst = color;
	}
}

t_img	*ft_init_img(void *mlx, t_img *img, int width, int height)
{	
	img->img = mlx_new_image(mlx, width, height);
	img->data_addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
	&(img->line_size), &(img->endian));
	img->transparency = 1;
	img->width = width;
	img->height = height;
	ft_fill_img(img, 0xFF000000);
	return (img);
}

void	ft_fill_img(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != img->height)
	{
		j = 0;
		while (j != img->width)
		{
			ft_put_pixel(img, j, i, color);
			++j;
		}
		i++;
	}
}
