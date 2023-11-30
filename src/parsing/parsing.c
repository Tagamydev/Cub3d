/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:29:48 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/30 20:15:51 by lyandriy         ###   ########.fr       */
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
