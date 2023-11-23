/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:25:06 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/23 20:23:41 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	free_aux(void *to_free)
{
	free(to_free);
	to_free = NULL;
}

int	ft_free_struct(t_cub *cub)
{
	int	count;

	count = 0;
	if (cub)
	{
		if (cub->map)
		{
			while (count < (int)cub->map_height)
			{
				free(cub->map[count]);
				count++;
			}
			free(cub->map);
		}
		free_aux(cub->no_texture->data_addr);
		free_aux(cub->no_texture);
		cub->no_texture = NULL;
		free_aux(cub->so_texture->data_addr);
		free_aux(cub->so_texture);
		free_aux(cub->ea_texture->data_addr);
		free_aux(cub->ea_texture);
		free_aux(cub->we_texture->data_addr);
		free_aux(cub->we_texture);
		free_aux(cub);
	}
	return (0);
}