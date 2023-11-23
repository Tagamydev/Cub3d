/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:15:25 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/23 22:36:51 by samusanc         ###   ########.fr       */
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
	img->data_addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
	&(img->line_size), &(img->endian));
	img->pixel_addr = (int *)mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
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

int	get_min_2(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	**alloc_tex(size_t size)
{
	int		**result;
	size_t	i;
	size_t	j;

	i = 0;
	if (!size || size < 0)
		return (NULL);
	result = malloc(sizeof(int *) * (size + 1));
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[i] = malloc(sizeof(int) * (size + 1));
		if (!result[i])
		{
			j = 0;
			while (j < i)
				free(result[j++]);
			free(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}

t_tex	*img_to_tex(t_img *img)
{
	int		**result;
	t_tex	*all;
	size_t	x;
	size_t	i;
	size_t	j;

	i = 0;
	x = get_min_2(img->width, img->height);
	result = alloc_tex(x);
	if (!result)
		return (NULL);
	all = malloc(sizeof(t_tex));
	if (!all)
	{
		free(result);
		return (NULL);
	}
	while (i < x)
	{
		j = 0;
		while (j < x)
		{
			result[i][j] = get_pixel_img(img, j, i);
			j++;
		}
		i++;
	}
	all->tex = result;
	all->size = x;
	return (all);
}

t_cub	*map_parsing(char *file)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub) * 1);
	if (!cub)
		return (NULL);
	cub->map = malloc(sizeof(size_t *) * 50);
	if (!cub->map)
		return (NULL);
	size_t	i = 0;
	cub->map[i++] = dup_ui_array((size_t[]){1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,1,1,1,1,1,1,1,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 47);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 47);
	cub->map_width = 47;
	cub->map_height = 47;

	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (NULL);
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	if (!cub->win)
		return (NULL);
	cub->ray_win = mlx_new_window(cub->mlx, cub->map_width * 10, cub->map_height * 10, "ray-casting");
	if (!cub->ray_win)
		return (NULL);
	cub->game = ft_init_img(cub->mlx, WIDTH, HEIGHT);
	if (!cub->game)
		return (NULL);
	cub->cam = ft_init_img(cub->mlx, WIDTH, HEIGHT);
	if (!cub->cam)
		return (NULL);
	cub->atm = ft_init_img(cub->mlx, WIDTH, HEIGHT);
	if (!cub->atm)
		return (NULL);
	if (!cub_open_utils(cub))
	{
		write(STDERR_FILENO, "error\n", 6);
		return (NULL);
	}
	cub->minimap = ft_init_img(cub->mlx, 140, 140);
	if (!cub->minimap)
		return (NULL);
	cub->ray_map = ft_init_img(cub->mlx, cub->map_width * 10, cub->map_height * 10);
	if (!cub->ray_map)
		return (NULL);

	cub->ea_texture = ft_open_img(cub->mlx, "./side.xpm");
	if (!cub->ea_texture)
		return (NULL);
	cub->we_texture = ft_open_img(cub->mlx, "./side.xpm");
	if (!cub->we_texture)
		return (NULL);
	cub->so_texture = ft_open_img(cub->mlx, "./so.xpm");
	if (!cub->so_texture)
		return (NULL);
	cub->no_texture = ft_open_img(cub->mlx, "./front.xpm");
	if (!cub->no_texture)
		return (NULL);
	cub->black = ft_open_img(cub->mlx, "./src/img/black.xpm");
	if (!cub->no_texture)
		return (NULL);

	cub->no_t = img_to_tex(cub->no_texture);
	if (!cub->no_t)
		return (NULL);
	cub->so_t = img_to_tex(cub->so_texture);
	if (!cub->so_t)
		return (NULL);
	cub->we_t = img_to_tex(cub->we_texture);
	if (!cub->we_t)
		return (NULL);
	cub->ea_t = img_to_tex(cub->ea_texture);
	if (!cub->ea_t)
		return (NULL);
	cub->black_t = img_to_tex(cub->black);
	if (!cub->black_t)
		return (NULL);

	//=============================================//
	cub->color_ground = 0x00FF0000;
	cub->color_sky = 0x00FF00FF;
	cub->player_px = 40;//6
	cub->player_py = 22;//18
	cub->player_a = 0;
	//=============================================//
	cub->minimap_zoom = ZOOM_L;
	cub->cam_status = OFF;
	cub->camera_speed = 2;
	cub->player_px += 0.5;
	cub->player_py += 0.5;
	put_deltas(cub);
	cub->door = 0;
	cub->fisheye = 0;
	cub->handx = 0;
	cub->handy = 0;
	cub->frame = 0;
	cub->cam_animation = 0;
	//=============================================//
	return (cub);
	(void)file;
}
