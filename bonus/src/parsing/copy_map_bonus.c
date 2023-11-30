/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:50:53 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/25 18:41:15 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	count_height_archive(int fd, int *height_archive)
{
	int		pos;
	char	*ret;

	pos = 1;
	*height_archive = 0;
	ret = get_next_line(fd);
	if (!ret)
		return (0);
	while (ret)
	{
		free(ret);
		*height_archive += 1;
		ret = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	copy_archive(int fd, char **archive, int height_archive)
{
	int	count;

	count = 0;
	archive[count] = get_next_line(fd);
	if (archive[count] == NULL)
	{
		close(fd);
		free(archive);
		return (0);
	}
	while (count < (height_archive - 1))
	{
		count++;
		archive[count] = get_next_line(fd);
		if (archive[count] == NULL)
			break ;
	}
	archive[count + 1] = NULL;
	close(fd);
	return (1);
}

void	check_map_widths(t_cub *cub, char **archive)
{
	size_t	count_line;
	size_t	count_int;

	count_line = 0;
	while (archive[count_line])
	{
		count_int = 0;
		while (archive[count_line][count_int] != '\n'
			&& archive[count_line][count_int] != '\0')
			count_int++;
		if (count_int > cub->map_width)
			cub->map_width = count_int;
		count_line++;
	}
}

int	copy_map(t_cub *cub, char **archive)
{
	int	count;

	count = 0;
	cub->map = malloc(sizeof(size_t) * (cub->map_height));
	if (!cub->map)
		return (0);
	check_map_widths(cub, archive);
	while ((size_t)count < (cub->map_height))
	{
		cub->map[count] = malloc(sizeof(size_t) * (cub->map_width));
		if (!cub->map[count])
			return (0);
		if (!check_char_of_str(cub, archive, &count))
			return (0);
		count++;
	}
	return (1);
}
