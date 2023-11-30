/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:15:25 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 20:21:25 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

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

void	get_pixel_img_to_result(t_img *img, int **result, size_t *x, size_t *i)
{
	size_t	j;

	j = 0;
	while (j < *x)
	{
		result[*i][j] = get_pixel_img(img, j, *i);
		j++;
	}
	*i += 1;
}

t_tex	*img_to_tex(t_img *img)
{
	int		**result;
	t_tex	*all;
	size_t	x;
	size_t	i;

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
		get_pixel_img_to_result(img, result, &x, &i);
	all->tex = result;
	all->size = x;
	return (all);
}
