/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:15:25 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/25 18:21:08 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

size_t	*dup_ui_array(size_t *array, size_t len)
{
	size_t	*result;
	size_t	i;

	i = 0;
	result = NULL;
	result = malloc((sizeof(size_t) * (len + 1)));
	if (!result)
		return (NULL);
	while (i != len)
	{
		result[i] = array[i];
		i++;
	}
	return (result);
}

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

t_img	*ft_init_img(void *mlx, int width, int height)
{
	t_img	*img;

	img = malloc(sizeof(t_img) * 1);
	if (!img)
		return (NULL);
	img->img = mlx_new_image(mlx, width, height);
	img->data_addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
	&(img->line_size), &(img->endian));
	img->transparency = 1;
	img->width = width;
	img->height = height;
	ft_fill_img(img, 0xFF000000);
	return (img);
}

t_img	*ft_open_img(void *mlx, char *path)
{
	t_img	*img;

	img = malloc(sizeof(t_img) * 1);
	if (!img)
		return (NULL);
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img)
		return (NULL);
	img->data_addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_size), &(img->endian));
	img->pixel_addr = (int *)mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_size), &(img->endian));
	return (img);
}

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
