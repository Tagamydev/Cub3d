/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:07:45 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 17:26:38 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	ft_draw_pixel(t_point point, t_img *img)
{
	ft_put_pixel(img, point.x, point.y, point.color);
}

static void	ft_ft_draw_map(t_fdfc *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x != (fdf->map->width - 1))
				ft_put_line(ft_proyect(ft_get_point(fdf->map->map, x, y), \
				fdf), ft_proyect(ft_get_point(fdf->map->map, x + 1, y), fdf), \
				&fdf->map_display);
			if (y != (fdf->map->height - 1))
				ft_put_line(ft_proyect(ft_get_point(fdf->map->map, x, y), \
				fdf), ft_proyect(ft_get_point(fdf->map->map, x, y + 1), fdf), \
				&fdf->map_display);
			x++;
		}
		y++;
	}
}

static void	ft_ft_draw_mini_map(t_fdfc *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x != (fdf->map->width - 1))
				ft_put_line(\
				ft_proyect_minimap(ft_get_point(fdf->map->map, x, y), \
				fdf), ft_proyect_minimap(ft_get_point(fdf->map->map, x + 1, y), \
				fdf), &fdf->map_display);
			if (y != (fdf->map->height - 1))
				ft_put_line(\
				ft_proyect_minimap(ft_get_point(fdf->map->map, x, y), \
				fdf), \
				ft_proyect_minimap(ft_get_point(fdf->map->map, x, y + 1), fdf), \
				&fdf->map_display);
			x++;
		}
		y++;
	}
}

void	ft_ft_draw(t_fdfc *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_fill_img(&fdf->map_display, 0xFF000000);
	ft_ft_draw_map(fdf);
	ft_ft_draw_mini_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->background.img, 0, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->map_display.img, 0, 0);
}
