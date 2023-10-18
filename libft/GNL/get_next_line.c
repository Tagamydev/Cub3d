/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:05:51 by samusanc          #+#    #+#             */
/*   Updated: 2023/06/29 20:08:37 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*ft_error(struct s_data_base *file)
{
	file->saved_line_len = 0;
	ft_free(&file->saved_line);
	return (NULL);
}

int	ft_verify_new_line(struct s_data_base *file)
{
	int	i;

	i = 0;
	if (!file->saved_line)
		return (0);
	while (i != file->saved_line_len)
	{
		if (file->saved_line[i] == '\n' || \
		file->saved_line[i] == '\r')
			return (1);
		++i;
	}
	return (0);
}

char	*ft_read_line(struct s_data_base *file, int *read_number, int fd)
{
	char	*str_for_realloc;

	str_for_realloc = NULL;
	*read_number = read(fd, file->buffer_line, BUFFER_SIZE);
	if (*read_number < 0)
		return (ft_error(file));
	str_for_realloc = ft_realloc(file->saved_line, file->buffer_line, \
	file->saved_line_len, *read_number);
	file->saved_line_len = file->saved_line_len + *read_number;
	ft_free(&file->saved_line);
	file->saved_line = str_for_realloc;
	return (file->saved_line);
}

char	*get_next_line(int fd)
{
	static struct s_data_base	file[OPEN_MAX];
	int							read_number;
	char						*result;

	read_number = 1;
	if (read(fd, 0, 0) < 0 || fd < 0 \
	|| BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (ft_error(&file[fd]));
	while (read_number)
	{
		if (ft_verify_new_line(&file[fd]))
			return (ft_split_lines(&file[fd]));
		if (!ft_read_line(&file[fd], &read_number, fd))
			return (0);
	}
	result = ft_mem_cpy(file[fd].saved_line, file[fd].saved_line_len);
	ft_error(&file[fd]);
	return (result);
}
/*
int	main(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		i = 4;

	fd = open(argv[1], O_RDONLY);
	while (i)
	{
		str = get_next_line(fd);
		printf("The line result:%s", str);
		write(1, "el resultado", 12);
		write(1, str, 100);
		--i;
	}
	//system("leaks -q aoeu");
	return (0);
}
*/
