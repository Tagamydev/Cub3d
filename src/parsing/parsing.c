/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:29:48 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/29 15:02:28 by samusanc         ###   ########.fr       */
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

void	print_parse(t_cub *cub)
{
	size_t i = 0;
	size_t y = 0;
	while (i < (cub->map_height))
	{
		y = 0;
		while (y < cub->map_width)
		{
			printf("[%zu]", cub->map[i][y]);
			y++;
		}
		printf("\n");
		i++;
	}
}


size_t	**alloc_new_map(size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	**result;

	i = 0;
	j = 0;
	result = ft_calloc(sizeof(size_t *), size);
	if (!result)
		return (NULL);
	while (i < size)
	{
		k = 0;
		result[i] = ft_calloc(sizeof(size_t), size);
		if (!result[i])
		{
			while (j < i)
				free(result[j++]);
			free(result);
			return (NULL);
		}
		while (k < size)
			result[i][k++] = 1;
		i++;
	}
	return (result);
}

int	resize_map(t_cub *cub)
{
	size_t	x;
	size_t	**new_map;
	size_t	i;
	size_t	j;
	size_t	tmp;

	if (cub->map_width > cub->map_height)
		x = cub->map_width;
	else
		x = cub->map_height;
	new_map = alloc_new_map(x + 40);
	if (!new_map)
		return (0);
	i = 0;
	j = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width)
		{
			tmp = cub->map[i][j];
			if (tmp == 9)
				tmp = 1;
			if (!BONUS)
			{
				if (tmp == 6)
					return (0);
			}
			new_map[i + 20][j + 20] = tmp;
			j++;
		}
		free(cub->map[i]);
		i++;
	}
	free(cub->map);
	cub->map = new_map;
	cub->map_width = x + 40;
	cub->map_height = x + 40;
	cub->player_px += 20;
	cub->player_py += 20;
	return (1);
}

float	**alloc_screen(void)
{
	size_t	i;
	size_t	j;
	size_t	k;
	float	**result;

	i = 0;
	j = 0;
	result = ft_calloc(sizeof(float *), HEIGHT);
	if (!result)
		return (NULL);
	while (i < HEIGHT)
	{
		k = 0;
		result[i] = ft_calloc(sizeof(float), WIDTH);
		if (!result[i])
		{
			while (j < i)
				free(result[j++]);
			free(result);
			return (NULL);
		}
		while (k < WIDTH)
			result[i][k++] = 30;
		i++;
	}
	return (result);
}

t_cub	*map_parsing(char *file)
{
	t_cub	*cub;

	cub = ft_calloc(sizeof(t_cub), 1);
	if (!cub)
		return (NULL);
	if (!init_cub(cub))
		return (NULL);
	//============================================================================//
	if (!get_line(fd_cub(file), file, cub))
	{
		printf("Error\n");
		return (NULL);
	}
	//============================================================================//
	if (!resize_map(cub))
		return (NULL);
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	if (!cub->win)
		return (NULL);
	//============================================================================//
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
	//============================================================================//
	cub->black = ft_open_img(cub->mlx, "./src/img/black.xpm");
	if (!cub->no_texture)
		return (NULL);
	cub->nina_texture = ft_open_img(cub->mlx, "./src/img/nina.xpm");
	if (!cub->nina_texture)
		return (NULL);
	cub->nina_t = img_to_tex(cub->nina_texture);
	if (!cub->nina_t)
		return (NULL);
	//============================================================================//
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
	//============================================================================//
	cub->black_t = img_to_tex(cub->black);
	if (!cub->black_t)
		return (NULL);
	if (cub->player_a == 2)
		cub->player_a = 270;
	else if (cub->player_a == 3)
		cub->player_a = 90;
	else if (cub->player_a == 4)
		cub->player_a = 180;
	else if (cub->player_a == 5)
		cub->player_a = 0;
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
	//============================================================================//
	cub->screen = alloc_screen();
	//============================================================================//
	return (cub);
}
