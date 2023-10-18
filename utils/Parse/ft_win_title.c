/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:46:09 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 14:20:39 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

char	*ft_map_format(char *str)
{
	char	**sp_dir;
	char	**sp_format;
	char	*result;
	int		i;

	i = 0;
	sp_dir = ft_split(str, '/');
	while (sp_dir[i])
		++i;
	if (i)
		--i;
	sp_format = ft_split(sp_dir[i], '.');
	result = NULL;
	if (sp_format[1])
	{
		if (ft_strncmp(sp_format[1], "fdf", ft_strlen(sp_format[1])) == 0)
			result = ft_strdup(sp_format[0]);
		else
			ft_error_log("INVALID_MAP_NOT_FDF_FILE");
	}
	ft_free_split(sp_dir);
	ft_free_split(sp_format);
	return (result);
}
