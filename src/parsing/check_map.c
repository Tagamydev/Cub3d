/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:40:47 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/25 18:41:01 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

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

int	check_char_of_str(t_cub *cub, char **arr, int *c)
{
	size_t	len;

	len = 0;
	while (arr[*c][len] || arr[*c][len] == '\n')
	{
		if (arr[*c][len] == '0' || arr[*c][len] == '1' || arr[*c][len] == 'N'
			|| arr[*c][len] == 'S' || arr[*c][len] == 'E'
			|| arr[*c][len] == 'W' || arr[*c][len] == ' ')
			char_of_str(cub, c, &len, arr);
		else if (arr[*c][len] == '\n')
		{
			if (len < cub->map_width)
			{
				while (len < cub->map_width)
					cub->map[*c][len++] = 9;
			}
			break ;
		}
		else
			return (0);
		if (!check_str_final(cub, c, &len, arr))
			break ;
		len++;
	}
	return (1);
}
