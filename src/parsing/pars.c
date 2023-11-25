/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:10:14 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/24 20:28:56 by lyandriy         ###   ########.fr       */
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

int	separate(t_cub *cub, char **archive, int height_archive)
{
	int	count_line;
	int	ret;

	count_line = 0;
	while (archive[count_line])
	{
		ret = fill_struct(cub, archive[count_line]);
		if (!ret)
			return (0);
		if (ret == 2)
			break;
		count_line++;
	}
	int count = 0;
	while (archive[count_line + count])
	{
		int i = 0;
		if (archive[count_line + count][i] == ' ')
		{
			while(archive[count_line + count][i] == ' ')
				i++;
			if (!archive[count_line + count][i] || archive[count_line + count][i] == '\n')
				return (0);
			count++;
		}
		if (archive[count_line + count][0] == '\n')
		{
			while (archive[count_line + count])
			{
				if (archive[count_line + count][0] != '\n')
					return (0);
				count++;
			}
		}
		else
			count++;
	}
	count = 0;
	while (archive[count_line + count])
	{
		if (archive[count_line + count][0] == '\n')
			break;
		count++;
	}
		height_archive = 0;
	cub->map_height = count;
	if (!copy_map(cub, &archive[count_line]))
		return (0);
	if (!check_maps(cub))
		return (0);
	return (1);
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
		height_archive = separate(cub, archive, height_archive);
		free_archive(archive);
		return (height_archive);
	}
	return (0);
}

void	print_parse(t_cub *cub)
{
	size_t i = 0;
	size_t y = 0;
	printf("map_width %zu\n", cub->map_width);
	printf("map_height %zu\n", cub->map_height);
	printf("color_ground %d\n", cub->color_ground);
	printf("color_sky %d\n", cub->color_sky);
	while (i < (cub->map_height))
	{
		y = 0;
		while (y < cub->map_width)
		{
			printf("%zu", cub->map[i][y]);
			y++;
		}
		printf("\n");
		i++;
	}
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
		printf("Error\n");
		ft_free_struct(cub);
		return (NULL);
	}
	print_parse(cub);
	printf("good map\n");
	return (cub);
}