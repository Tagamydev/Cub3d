/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:17:06 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/31 13:22:10 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	put_chunks_minimap(char **minimap, int i, int j, char c)
{
	if (c == '1')
		minimap[i][j] = 'W';
	else if (c == '0')
		minimap[i][j] = '0';
	else if (c == '2' || c == '3' || c == '4' || c == '5')
		minimap[i][j] = 'P';
	else if (c == '6' || c == '7')
		minimap[i][j] = 'D';
}

void	draw_square(t_img *img, t_square sq)
{
	int	i;
	int	j;
	int	x2;

	i = 0;
	while (i != sq.len)
	{
		j = 0;
		x2 = sq.x;
		while (j != sq.len)
		{
			ft_put_pixel(img, x2, sq.y, sq.color);
			j++;
			x2++;
		}
		i++;
		sq.y++;
	}
}

int	get_color_minimap(char c)
{
	if (c == 'W')
		return (COLOR_W);
	else if (c == 'P')
		return (COLOR_P);
	else if (c == 'D')
		return (COLOR_D);
	else
		return (COLOR_E);
}

void	put_pixels_minimap(char **minimap, t_cub *cub)
{
	int			size;
	int			i;
	int			j;
	t_square	sq;

	size = 140 / cub->minimap_zoom;
	i = 0;
	while (i != cub->minimap_zoom)
	{
		j = 0;
		while (j != cub->minimap_zoom)
		{
			sq.y = i * size;
			sq.x = j * size;
			sq.len = size;
			sq.color = get_color_minimap(minimap[i][j]);
			draw_square(cub->minimap, sq);
			j++;
		}
		i++;
	}
	(void)minimap;
	(void)cub;
}

void	draw_minimap(t_cub *cub)
{
	char	**minimap;
	int		x;
	int		y;

	x = (int)cub->player_px;
	y = (int)cub->player_py;
	minimap = alloc_minimap(cub->minimap_zoom);
	set_zero_minimap(minimap, cub->minimap_zoom);
	minimap[(cub->minimap_zoom / 2)] \
	[(cub->minimap_zoom / 2)] = 'P';
	put_walls_minimap(minimap, x, y, cub);
	put_pixels_minimap(minimap, cub);
	free_split(minimap);
	(void)cub;
}
