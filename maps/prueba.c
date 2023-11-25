/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:21:44 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/25 17:49:06 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

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

int	check_str_final(t_cub *cub, int *count, size_t *len_str, char **archive)
{
	if (archive[*count][*len_str + 1] == '\0')
	{
		if (*len_str < cub->map_width)
		{
			*len_str += 1;
			while (*len_str < cub->map_width)
			{
				cub->map[*count][*len_str] = 9;
				*len_str += 1;
			}
		}
		return (0);
	}
	return (1);
}

void	char_of_str(t_cub *cub, int *count, size_t *len_str, char **archive)
{
	if (archive[*count][*len_str] == '0')
		cub->map[*count][*len_str] = 0;
	else if (archive[*count][*len_str] == '1')
		cub->map[*count][*len_str] = 1;
	else if (archive[*count][*len_str] == 'N')
		cub->map[*count][*len_str] = 2;
	else if (archive[*count][*len_str] == 'S')
		cub->map[*count][*len_str] = 3;
	else if (archive[*count][*len_str] == 'E')
		cub->map[*count][*len_str] = 4;
	else if (archive[*count][*len_str] == 'W')
		cub->map[*count][*len_str] = 5;
	else if (archive[*count][*len_str] == ' ')
		cub->map[*count][*len_str] = 9;
}

int	check_char_of_str(t_cub *cub, char **archive, int *count)
{
	size_t	len_str;

	len_str = 0;
	while (archive[*count][len_str] || archive[*count][len_str] == '\n')
	{
		if (archive[*count][len_str] == '0' || archive[*count][len_str] == '1'
			|| archive[*count][len_str] == 'N' || archive[*count][len_str] == 'S'
			|| archive[*count][len_str] == 'E' || archive[*count][len_str] == 'W'
			|| archive[*count][len_str] == ' ')
			char_of_str(cub, count, &len_str, archive);
		else if (archive[*count][len_str] == '\n')
		{
			if (len_str < cub->map_width)
			{
				while (len_str < cub->map_width)
				{
					cub->map[*count][len_str] = 9;
					len_str++;
				}
			}
			break;
		}
		else
			return (0);
		if (!check_str_final(cub, count, &len_str, archive))
			break;
		len_str++;
	}
	return (1);
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
			break;
	}
	archive[count + 1] = NULL;
	close(fd);
	return (1);
}