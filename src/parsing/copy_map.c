/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:50:53 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/16 20:05:33 by lyandriy         ###   ########.fr       */
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

int	check_char_of_str(t_cub *cub, char **archive, int *count)
{
	size_t	len_str;

	len_str = 0;
	while (archive[*count][len_str])
	{
		if (archive[*count][len_str] == '1')
			break;
		len_str++;
		if (archive[*count][len_str] == '\0')
			return (0);
	}
	while (archive[*count][len_str] || archive[*count][len_str] == '\n')
	{
		if (archive[*count][len_str] == '0')
			cub->map[*count][len_str] = 0;
		else if (archive[*count][len_str] == '1')
			cub->map[*count][len_str] = 1;
		else if (archive[*count][len_str] == 'N')
			cub->map[*count][len_str] = 2;
		else if (archive[*count][len_str] == 'S')
			cub->map[*count][len_str] = 3;
		else if (archive[*count][len_str] == 'E')
			cub->map[*count][len_str] = 4;
		else if (archive[*count][len_str] == 'W')
			cub->map[*count][len_str] = 5;
		else if (archive[*count][len_str] == ' ')
			cub->map[*count][len_str] = 9;
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
		if (archive[*count][len_str + 1] == '\0')
		{
			if (len_str < cub->map_width)
			{
				len_str++;
				while (len_str < cub->map_width)
				{
					cub->map[*count][len_str] = 9;
					len_str++;
				}
			}
			break;
		}
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
	while (archive[count])
	{
		cub->map[count] = malloc(sizeof(size_t) * (cub->map_width));
		if (!cub->map[count])
			return (0);
		if (!check_char_of_str(cub, archive, &count))
			return (0);//return(ft_free); ft_free libera toda la memoria y retorna un 0;
		count++;
	}
	return (1);
}

int	count_height_archive(int fd, int *height_archive)
{
	int		pos;
	char	chars;

	pos = 1;
	*height_archive = 0;
	while (pos != 0)
	{
		pos = read(fd, &chars, 1);
		if (pos == -1)
			return (0);
		if (chars == '\n')
			*height_archive += 1;
	}
	*height_archive += 1;
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
		{
			close(fd);
			free_map(count, archive, fd);
			return (0);
		}
	}
	archive[count + 1] = NULL;
	close(fd);
	return (1);
}
