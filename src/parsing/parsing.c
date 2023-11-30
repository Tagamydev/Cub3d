/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:29:48 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/30 20:04:37 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	fd_cub(char *file)
{
	int	len;
	int	fd;

	len = ft_strlen(file);
	if (len > 4)
	{
		if (!ft_memcmp(&file[len - 4], ".cub", 4))
		{
			fd = open(file, O_RDONLY);
			return (fd);
		}
	}
	return (-1);
}

int	get_line(int fd, char *file, t_cub *cub)
{
	char	**archive;
	int		height_archive;

	if (fd < 0)
		return (0);
	if (!count_height_archive(fd, &height_archive))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	archive = malloc(sizeof(char *) * (height_archive + 1));
	if (!archive)
		return (0);
	if (copy_archive(fd, archive, height_archive))
	{
		height_archive = separate(cub, archive);
		free_archive(archive);
		return (height_archive);
	}
	return (0);
}

void	free_result(size_t **result, size_t *i)
{
	size_t	j;

	j = 0;
	while (j < *i)
		free(result[j++]);
	free(result);
}

size_t	**alloc_new_map(size_t size)
{
	size_t	i;
	size_t	k;
	size_t	**result;

	i = 0;
	result = ft_calloc(sizeof(size_t *), size);
	if (!result)
		return (NULL);
	while (i < size)
	{
		k = 0;
		result[i] = ft_calloc(sizeof(size_t), size);
		if (!result[i])
		{
			free_result(result, &i);
			return (NULL);
		}
		while (k < size)
			result[i][k++] = 1;
		i++;
	}
	return (result);
}

int	resize_map_aux(t_cub *cub, size_t *tmp, size_t *i, size_t **new_map)
{
	size_t	j;

	j = 0;
	while (j < cub->map_width)
	{
		*tmp = cub->map[*i][j];
		if (*tmp == 9)
			*tmp = 1;
		if (!BONUS)
		{
			if (*tmp == 6)
				return (0);
		}
		new_map[*i + 20][j + 20] = *tmp;
		j++;
	}
	free(cub->map[*i]);
	*i += 1;
	return (1);
}

int	resize_map(t_cub *cub)
{
	size_t	x;
	size_t	**new_map;
	size_t	i;
	size_t	tmp;

	if (cub->map_width > cub->map_height)
		x = cub->map_width;
	else
		x = cub->map_height;
	new_map = alloc_new_map(x + 40);
	if (!new_map)
		return (0);
	i = 0;
	while (i < cub->map_height)
	{
		if (!resize_map_aux(cub, &tmp, &i, new_map))
			return (0);
	}
	free(cub->map);
	cub->map = new_map;
	cub->map_width = x + 40;
	cub->map_height = x + 40;
	cub->player_px += 20;
	cub->player_py += 20;
	return (1);
}

t_spr	*new_sprite(size_t x, size_t y, int frame)
{
	t_spr	*new;

	new = malloc(sizeof(t_spr));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->next_frame = 0;
	new->next_blink = 0;
	new->blink = 0;
	if (frame > 4)
		frame = 4;
	new->frame = frame;
	return (new);
}

int	put_sprites_aux(t_cub *cub, size_t *tmp)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	x = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width)
		{
			*tmp = cub->map[i][j];
			if (*tmp == 10)
			{
				cub->sprites[x] = new_sprite(j, i, ft_random(1, 0, 4));
				if (!cub->sprites[x++])
					return (0);
				cub->map[i][j] = 0;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	count_tam_spr(t_cub *cub, size_t *tmp, size_t *k)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width)
		{
			*tmp = cub->map[i][j];
			if (!BONUS)
			{
				if (*tmp == 10)
					return (0);
			}
			if (*tmp == 10)
				*k += 1;
			j++;
		}
		i++;
	}
	return (1);
}

int	put_sprites(t_cub *cub)
{
	size_t	k;
	size_t	tmp;

	k = 0;
	if (!count_tam_spr(cub, &tmp, &k))
		return (0);
	cub->sprites = malloc(sizeof(t_spr *) * (k + 1));
	if (!cub->sprites)
		return (0);
	cub->sprites[k] = NULL;
	if (!put_sprites_aux(cub, &tmp))
		return (0);
	return (1);
}

void	free_result_float(float **result, size_t *i)
{
	size_t	j;

	j = 0;
	while (j < *i)
		free(result[j++]);
	free(result);
}

float	**alloc_screen(void)
{
	size_t	i;
	size_t	k;
	float	**result;

	i = 0;
	result = ft_calloc(sizeof(float *), HEIGHT);
	if (!result)
		return (NULL);
	while (i < HEIGHT)
	{
		k = 0;
		result[i] = ft_calloc(sizeof(float), WIDTH);
		if (!result[i])
		{
			free_result_float(result, &i);
			return (NULL);
		}
		while (k < WIDTH)
			result[i][k++] = 30;
		i++;
	}
	return (result);
}

int	init_img_cub(t_cub *cub)
{
	cub->game = ft_init_img(cub->mlx, WIDTH, HEIGHT);
	if (!cub->game)
		return (0);
	cub->cam = ft_init_img(cub->mlx, WIDTH, HEIGHT);
	if (!cub->cam)
		return (0);
	cub->atm = ft_init_img(cub->mlx, WIDTH, HEIGHT);
	if (!cub->atm)
		return (0);
	if (!cub_open_utils(cub))
	{
		write(STDERR_FILENO, "error\n", 6);
		return (0);
	}
	cub->minimap = ft_init_img(cub->mlx, 140, 140);
	if (!cub->minimap)
		return (0);
	return (1);
}

int	do_img_to_tex(t_cub *cub)
{
	cub->no_t = img_to_tex(cub->no_texture);
	if (!cub->no_t)
		return (0);
	cub->so_t = img_to_tex(cub->so_texture);
	if (!cub->so_t)
		return (0);
	cub->we_t = img_to_tex(cub->we_texture);
	if (!cub->we_t)
		return (0);
	cub->ea_t = img_to_tex(cub->ea_texture);
	if (!cub->ea_t)
		return (0);
	return (1);
}

void	map_parsing_aux(t_cub *cub)
{
	if (cub->player_a == 2)
		cub->player_a = 270;
	else if (cub->player_a == 3)
		cub->player_a = 90;
	else if (cub->player_a == 4)
		cub->player_a = 180;
	else if (cub->player_a == 5)
		cub->player_a = 0;
	cub->player_a += 0.1;
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
	cub->screen = alloc_screen();
}

t_cub	*map_parsing(char *file)
{
	t_cub	*cub;

	cub = ft_calloc(sizeof(t_cub), 1);
	if (!cub)
		return (NULL);
	if (!init_cub(cub))
		return (NULL);
	if (!get_line(fd_cub(file), file, cub))
	{
		write(STDERR_FILENO, "Error\nFailed map\n", 17);
		exit(-1);
	}
	if (!resize_map(cub))
		return (NULL);
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	if (!cub->win)
		return (NULL);
	if (!init_img_cub(cub) || !open_all_img(cub) || !img_to_tex_all(cub)
		|| !put_sprites(cub) || !do_img_to_tex(cub))
		return (NULL);
	cub->black_t = img_to_tex(cub->black);
	if (!cub->black_t)
		return (NULL);
	map_parsing_aux(cub);
	return (cub);
}
