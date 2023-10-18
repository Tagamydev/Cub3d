/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:31 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 14:09:57 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

char	*get_all_doc(int fd)
{
	static struct s_data_base	file[OPEN_MAX];
	int							read_number;
	char						*result;

	read_number = 1;
	if (read(fd, 0, 0) < 0 || fd < 0 \
	|| BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (ft_error(&file[fd]));
	while (read_number)
		if (!ft_read_line(&file[fd], &read_number, fd))
			return (0);
	result = ft_mem_cpy(file[fd].saved_line, file[fd].saved_line_len);
	ft_error(&file[fd]);
	return (result);
}
