/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:15:25 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/18 06:20:35 by samusanc         ###   ########.fr       */
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
	return (img);
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
	cub->map[i++] = dup_ui_array((size_t[]){1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,1,0,1,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,0,1,0,1,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,1,1,1,1,1,1,1,0,0,0,0,5,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 24);
	cub->map[i++] = dup_ui_array((size_t[]){1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 24);
	cub->map_width = 24;
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
	cub->minimap = ft_init_img(cub->mlx, 140, 140);
	if (!cub->minimap)
		return (NULL);
	cub->ray_map = ft_init_img(cub->mlx, cub->map_width * 10, cub->map_height * 10);
	if (!cub->ray_map)
		return (NULL);
	cub->color_ground = 0x00FF0000;
	cub->color_sky = 0x000000FF;
	cub->minimap_zoom = ZOOM_L;
	cub->player_px = 13;//6
	cub->player_py = 22;//18
	cub->player_px += 0.5;
	cub->player_py += 0.5;
	cub->player_a = 270;
	put_deltas(cub);
	cub->map_4_ray = ft_calloc(sizeof(int), ((cub->map_width * cub->map_height) + 1));
	cub->camera_speed = 2;
	cub->door = 1;
	cub->fisheye = 0;
	if (!cub->map_4_ray)
		return (NULL);
	return (cub);
	(void)file;
}
