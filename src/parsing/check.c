/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:07:46 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/25 18:42:47 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	do_check(t_cub *cub, size_t *count_line, size_t *count_int, int *flag)
{
	if (cub->map[*count_line][*count_int] == 9)
		*count_int += 1;
	else if ((cub->map[*count_line][*count_int] >= 2
		&& cub->map[*count_line][*count_int] <= 5))
	{
		cub->player_a = cub->map[*count_line][*count_int];
		cub->player_px = *count_int;
		cub->player_py = *count_line;
		if (!check_wall(cub, count_line, count_int))
			return (0);
		*flag += 1;
	}
	else if (cub->map[*count_line][*count_int] == 1)
		*count_int += 1;
	else if (cub->map[*count_line][*count_int] == 0)
	{
		if (!check_wall(cub, count_line, count_int))
			return (0);
	}
	return (1);
}

int	check_maps(t_cub *cub)
{
	size_t	count_line;
	size_t	count_int;
	int		flag_player;

	count_line = 0;
	flag_player = 0;
	while (count_line < (cub->map_height - 1))
	{
		count_int = 0;
		while (count_int < cub->map_width)
		{
			if (!do_check(cub, &count_line, &count_int, &flag_player))
				return (0);
		}
		count_line++;
	}
	if (flag_player != 1)
		return (0);
	return (1);
}
