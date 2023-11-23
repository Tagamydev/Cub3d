/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:15:30 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/05 14:59:24 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	set_zero_minimap(char **minimap, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != size)
	{
		j = 0;
		while (j != size)
			minimap[i][j++] = '0';
		i++;
	}
}

void	write_minimap(char **minimap, int size)
{
	int	i;

	i = 0;
	while (i != size)
	{
		write(1, minimap[i], size);
		write(1, "\n", 1);
		i++;
	}
}

char	**alloc_minimap(int size)
{
	char	**minimap;
	int		i;

	i = 0;
	minimap = malloc(sizeof(char *) * (size + 1));
	if (!minimap)
	{
		perror("cub: ");
		exit(-1);
	}
	minimap[size] = NULL;
	while (i != size)
	{
		minimap[i] = malloc(sizeof(char *) * (size + 1));
		if (!minimap[i])
		{
			perror("cub: ");
			exit(-1);
		}
		minimap[i][size] = '\0';
		i++;
	}
	return (minimap);
}

static void	init_put_walls(t_put_walls *wall, int x, int y, int zoom)
{
	wall->i = 0;
	wall->j = 0;
	wall->minx = x - (zoom / 2);
	wall->y2 = y - (zoom / 2);
	wall->x2 = wall->minx;
}

void	put_walls_minimap(char **minimap, int x, int y, t_cub *cub)
{
	t_put_walls	wall;

	init_put_walls(&wall, x, y, cub->minimap_zoom);
	while (wall.i != cub->minimap_zoom)
	{
		wall.j = 0;
		wall.x2 = wall.minx;
		while (wall.j != cub->minimap_zoom)
		{
			if (wall.x2 >= 0 && wall.y2 >= 0)
			{
				if (wall.x2 < (int)cub->map_width && \
						wall.y2 < (int)cub->map_height)
					put_chunks_minimap(minimap, wall.i, wall.j, \
							cub->map[wall.y2][wall.x2] + '0');
			}
			wall.x2++;
			wall.j++;
		}
		wall.y2++;
		wall.i++;
	}
}
