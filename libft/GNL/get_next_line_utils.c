/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:16:06 by samusanc          #+#    #+#             */
/*   Updated: 2023/05/26 19:22:12 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_split_lines(struct s_data_base *file)
{
	int		i;
	char	*string_for_db;
	char	*string_result;

	i = 0;
	while (file->saved_line[i] != '\n' && file->saved_line[i] != '\r')
		++i;
	string_result = ft_mem_cpy(file->saved_line, i + 1);
	string_for_db = ft_mem_cpy((file->saved_line + (i + 1)), \
	(file->saved_line_len - (i + 1)));
	file->saved_line_len = file->saved_line_len - (i + 1);
	ft_free(&file->saved_line);
	file->saved_line = string_for_db;
	return (string_result);
}

char	*ft_mem_cpy(char *str, int len)
{
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	result = malloc(sizeof(char) * ((int)len + 1));
	if (!result || !str || len <= 0)
	{
		if (result)
			ft_free(&result);
		return (NULL);
	}
	while (i <= len)
		result[i++] = '\0';
	i = 0;
	while (i != len)
		result[i++] = *str++;
	return (result);
}

char	*ft_realloc(char *str1, char *str2, int str1_len, int str2_len)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str1 || !str2)
	{
		if (str1)
			return (ft_mem_cpy(str1, str1_len));
		if (str2)
			return (ft_mem_cpy(str2, str2_len));
		return (NULL);
	}
	result = malloc(sizeof(char) * ((int)(str1_len + str2_len + 1)));
	if (!result)
		return (NULL);
	result[(str1_len + str2_len)] = '\0';
	while (i != str1_len)
		result[i++] = *str1++;
	while (j != str2_len)
		result[i++] = str2[j++];
	return (result);
}
