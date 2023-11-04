/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:10:14 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/04 22:05:10 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	count_char(int fd, int *count)
{
	int		read_return;
	char	character;

	character = 0;
	while (character != '\n' || character != '\0')
	{
		read_return = read(fd, character, 1);
		if (read_return == 0)
			break;
		if (read_return == -1)
			return (0);
		*count += 1;
	}
	return (1);
}

int	copy_line(int fd, char *line)
{
	int		count;
	int		read_return;
	char	character;

	character = 0;
	while (character != '\n' || character != '\0')
	{
		read_return = read(fd, character, 1);
		if (read_return == 0 || character == '\n')
			break;
		if (read_return == -1)
			return (0);
		line[count] = character;
		count++;
	}
	line[count] = '\0';
	return (1);
}

void	data_addres(char *line, char *data_addr, int *count)
{
	int	i;

	i = 0;
	*count += 2;
	while (line[*count] == ' ')
		*count += 1;
	if (line[*count])
	{
		while (line[*count + i] != '\t' || line[*count + i] != ' ')
			i++;
		data_addr = malloc(sizeof(char) * (i + 1));
		if (!data_addr)
			return (NULL);//exit???
		ft_strlcpy(data_addr, &line[*count], i);
	}
}

void	identifier_color(char *line, int *color, int *count)
{
	int		i;
	int		numb;
	int		rgb[3];
	char	*digit;

	numb = 0;
	*count += 2;
	while (line[*count] == ' ')
		*count += 1;
	if (line[*count])
	{
		while (line[*count])
		{
			if (!ft_isdigit(line[*count]) || numb >= 3)
				return (0);
			i = 0;
			while (ft_isdigit(line[*count + i]))
				i++;
			digit = malloc(sizeof(char) * (i + 1));
			if (!digit)
				return (0);
			ft_strlcpy(digit, &line[*count], i);
			*count += i;
			rgb[numb] = ft_atoi(digit);
			free(digit);
			if (rgb[numb] < 0 || rgb[numb] > 255)
				return (0);
			numb++;
			while (line[*count] == ' ')
				*count += 1;
			if (line[*count] == ',')
				*count += 1;
			while (line[*count] == ' ')
				*count += 1;
		}
		color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	}
}

int	fill_struct(t_cub *cub, char *line)
{
	int	count;

	count = 0;
	while (line[count] == ' ')
		count++;
	if (!ft_strncmp(&line[count], 'NO ', 3))
		dat_addres(&line[count], &cub->no_texture->data_addr, &count);
	else if (!ft_strncmp(&line[count], 'SO ', 3))
		dat_addres(&line[count], &cub->so_texture->data_addr, &count);
	else if (!ft_strncmp(&line[count], 'EA ', 3))
		dat_addres(&line[count], &cub->ea_texture->data_addr, &count);
	else if (!ft_strncmp(&line[count], 'WE ', 3))
		dat_addres(&line[count], &cub->we_texture->data_addr, &count);
	else if (!ft_strncmp(&line[count], 'F ', 2))
		identifier_color(&line[count], &cub->color_ground, &count);
	else if (!ft_strncmp(&line[count], 'C ', 2))
		identifier_color(&line[count], &cub->color_sky, &count);
	free(line);
}

int	get_line(int fd, char *file, t_cub *cub)
{
	int		fd2;
	int		count;
	char	*line;

	count = 0;
	line = NULL;
	if (fd >= 0)
	{
		while (fd != 0)
		{
			fd2 = open(file, fd2, O_RDONLY);
			if (!count_char(fd, &count))
				break;
			line = malloc(sizeof(char) * (count + 1));
			if (!line)
				return (0);
			if (!copy_line(fd2, &line))
				break;
			fill_struct(cub, line);
		}
		if (fd == 0 || fd2 == 0)
			return (1);
	}
	return (0);
}

int	fd_cub(char *file)
{
	int	len;
	int	fd;

	len = ft_strlen(file);
	if (len > 4)
	{
		if (!ft_memcmp(&file[len - 4], ".cub", 4))
		{
			fd = open(file, fd, O_RDONLY);
			return (fd);
		}
	}
	return (-1);
}

t_cub	*map_parsing(char *file)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub) * 1);
	if (!cub)
		return (NULL);
	get_line(fd_cub(file), file, cub);
}