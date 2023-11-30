/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:50:45 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:50:59 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	close_doors(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)cub->map_height)
	{
		j = 0;
		while (j < (int)cub->map_width)
		{
			if (cub->map[i][j] == 7)
				cub->map[i][j] = 6;
			j++;
		}
		i++;
	}
	cub->door = 0;
}
