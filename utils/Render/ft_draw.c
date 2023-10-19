/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:07:45 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/19 10:52:29 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	ft_draw_pixel(t_point point, t_img *img)
{
	ft_put_pixel(img, point.x, point.y, point.color);
}

static void	ft_ft_draw_map(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < cub->map->height)
	{
		x = 0;
		while (x < cub->map->width)
		{
			if (x != (cub->map->width - 1))
				ft_put_line(ft_proyect(ft_get_point(cub->map->map, x, y), \
				cub), ft_proyect(ft_get_point(cub->map->map, x + 1, y), cub), \
				&cub->map_display);
			if (y != (cub->map->height - 1))
				ft_put_line(ft_proyect(ft_get_point(cub->map->map, x, y), \
				cub), ft_proyect(ft_get_point(cub->map->map, x, y + 1), cub), \
				&cub->map_display);
			x++;
		}
		y++;
	}
}

static void	ft_ft_draw_mini_map(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < cub->map->height)
	{
		x = 0;
		while (x < cub->map->width)
		{
			if (x != (cub->map->width - 1))
				ft_put_line(\
				ft_proyect_minimap(ft_get_point(cub->map->map, x, y), \
				cub), ft_proyect_minimap(ft_get_point(cub->map->map, x + 1, y), \
				cub), &cub->map_display);
			if (y != (cub->map->height - 1))
				ft_put_line(\
				ft_proyect_minimap(ft_get_point(cub->map->map, x, y), \
				cub), \
				ft_proyect_minimap(ft_get_point(cub->map->map, x, y + 1), cub), \
				&cub->map_display);
			x++;
		}
		y++;
	}
}

void	ft_ft_draw(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_fill_img(&cub->map_display, 0xFF000000);
	ft_ft_draw_map(cub);
	ft_ft_draw_mini_map(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->background.img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->map_display.img, 0, 0);
}
