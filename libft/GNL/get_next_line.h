/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:44:16 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/07 17:52:35 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# if !defined (BUFFER_SIZE)
#  define BUFFER_SIZE 1000
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

struct s_data_base {
	char	buffer_line[BUFFER_SIZE + 1];
	char	*saved_line;
	int		saved_line_len;
};

char	*ft_free(char **str);
char	*ft_error(struct s_data_base *file);
int		ft_verify_new_line(struct s_data_base *file);
char	*ft_mem_cpy(char *str, int len);
char	*ft_realloc(char *str1, char *str2, int str1_len, int str2_len);
char	*ft_read_line(struct s_data_base *file, int *read_number, int fd);
char	*ft_split_lines(struct s_data_base *file);
char	*get_next_line(int fd);;
#endif
