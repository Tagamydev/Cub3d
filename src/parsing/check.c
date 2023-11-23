/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:07:46 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/19 16:50:49 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	search_wall_east(t_cub *cub, int count_line, int count_int)
{
	int width;

	width = (int) cub->map_width;
	while (count_int < width)
	{
		if (cub->map[count_line][count_int] == 1)
			return (1);
		count_int++;
	}
	return (0);
}

int	search_wall_west(t_cub *cub, int count_line, int count_int)
{
	while (count_int >= 0)
	{
		if (cub->map[count_line][count_int] == 1)
			return (1);
		count_int--;
	}
	return (0);
}

int	search_wall_north(t_cub *cub, int count_line, int count_int)
{
	while (count_line >= 0)
	{
		if (cub->map[count_line][count_int] == 1)
			return (1);
		count_line--;
	}
	return (0);
}

int	search_wall_south(t_cub *cub, int count_line, int count_int)
{
	int height;

	height = (int) cub->map_height;
	while (count_line < height)
	{
		if (cub->map[count_line][count_int] == 1)
			return (1);
		count_line++;
	}
	return (0);
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
			if (cub->map[count_line][count_int] == 9)
				count_int++;
			else if ((cub->map[count_line][count_int] >= 2
				&& cub->map[count_line][count_int] <= 5))
			{
				if (!search_wall_east(cub, (int)count_line, (int)count_int))
					return (0);
				if (!search_wall_west(cub, (int)count_line, (int)count_int))
					return (0);
				if (!search_wall_north(cub, (int)count_line, (int)count_int))
					return (0);
				if (!search_wall_south(cub, (int)count_line, (int)count_int))
					return (0);
				flag_player++;
				count_int++;
			}
			else if (cub->map[count_line][count_int] == 1)
				count_int++;
			else if (cub->map[count_line][count_int] == 0)
			{
				if (!search_wall_east(cub, (int)count_line, (int)count_int))
					return (0);
				if (!search_wall_west(cub, (int)count_line, (int)count_int))
					return (0);
				if (!search_wall_north(cub, (int)count_line, (int)count_int))
					return (0);
				if (!search_wall_south(cub, (int)count_line, (int)count_int))
					return (0);
				count_int++;
			}
		}
		count_line++;
	}
	if (flag_player != 1)
		return (0);
	return (1);
}
