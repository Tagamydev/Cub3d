/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:40:47 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/30 18:41:40 by lyandriy         ###   ########.fr       */
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
	else if (archive[*count][*len_str] == 'D')
		cub->map[*count][*len_str] = 6;
	else if (archive[*count][*len_str] == 'G')
		cub->map[*count][*len_str] = 10;
}

int	check_char_of_str(t_cub *cub, char **ar, int *c)
{
	size_t	len;

	len = 0;
	while (ar[*c][len] || ar[*c][len] == '\n')
	{
		if (ar[*c][len] == '0' || ar[*c][len] == '1' || ar[*c][len] == 'N'
			|| ar[*c][len] == 'S' || ar[*c][len] == 'E' || ar[*c][len] == 'W'
			|| ar[*c][len] == ' ' || ar[*c][len] == 'D' || ar[*c][len] == 'G')
			char_of_str(cub, c, &len, ar);
		else if (ar[*c][len] == '\n')
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
		if (!check_str_final(cub, c, &len, ar))
			break ;
		len++;
	}
	return (1);
}
