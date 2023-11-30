/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:01:39 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:01:54 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void write_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != (int)cub->map_height)
	{
		j = 0;
		while (j != (int)cub->map_width)
		{
			printf("[%zu]", cub->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
