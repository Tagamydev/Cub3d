/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:16:18 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/30 15:11:50 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	fill_img_sky_n_ground(t_img *img, int color1, int color2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != (img->height / 2))
	{
		j = 0;
		while (j != img->width)
		{
			ft_put_pixel(img, j, i, color1);
			++j;
		}
		i++;
	}
	while (i != img->height)
	{
		j = 0;
		while (j != img->width)
		{
			ft_put_pixel(img, j, i, color2);
			++j;
		}
		i++;
	}
}

void	set_zero_minimap(char minimap[7][7])
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i != 7)
	{
		j = 0;
		while (j != 7)
			minimap[i][j++] = '0';
		i++;
	}
}

void	write_minimap(char minimap[7][7])
{
	write(1, minimap[0], 7);
	write(1, "\n", 1);
	write(1, minimap[1], 7);
	write(1, "\n", 1);
	write(1, minimap[2], 7);
	write(1, "\n", 1);
	write(1, minimap[3], 7);
	write(1, "\n", 1);
	write(1, minimap[4], 7);
	write(1, "\n", 1);
	write(1, minimap[5], 7);
	write(1, "\n", 1);
	write(1, minimap[6], 7);
	write(1, "\n", 1);
}

void	draw_minimap(t_cub *cub)
{
	char	minimap[7][7];
	int		x;
	int		y;

	x = (int)cub->player_px;
	y = (int)cub->player_py;
	set_zero_minimap(minimap);
	minimap[3][3] = 'P';
	write_minimap(minimap);
	printf("player position: x:%d, y:%d\n", x, y);
	(void)cub;
}

void	start_cub(t_cub *cub)
{
	fill_img_sky_n_ground(cub->game, cub->color_sky, cub->color_ground);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->game->img, 0, 0);
	ft_fill_img(cub->minimap, 0x00000000);
	draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0, 0);
	return ;
	(void)cub;
}
