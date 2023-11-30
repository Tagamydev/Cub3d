/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:03:15 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:03:33 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	draw_walls(t_cub *cub, t_ray ray, size_t actual_ray, size_t total_rays, int side, int win)
{
	int		i;
	int		j;
	int		k;
	int		start_x;
	int		len;
	int		offset_up;
	int		offset_down;
	int		fog;
	int		actual_chunk;
	int		size;
	int		real_wall_ds;
	int		**tex;
	float	pixel;
	float	start_point;
	float	end_point;
	float	x;
	float	color_ground_mix;
	double	distance;
	size_t	wall_len;

	//======================================================================================//
	i = 0;
	fog = 0;
	len = (float)WIDTH / total_rays;
	start_x = len * actual_ray;
	distance = (240 * 15) / ray.distance;
	distance = distance / 5;
	offset_up = ((HEIGHT / 2.5) - distance);
	offset_down = (HEIGHT / 1.25 - offset_up);
	color_ground_mix = 0;
	wall_len = 0;
	//======================================================================================//
	if (side == 0x00FF0000)
	{
		size = cub->so_t->size;
		tex = cub->so_t->tex;
		actual_chunk = size - (get_decimal(ray.x) * (float)size);
		//printf("south\n");
	}
	else if (side == 0x00FF00FF)
	{
		size = cub->no_t->size;
		tex = cub->no_t->tex;

		actual_chunk = (get_decimal(ray.x) * (float)size);
		//printf("north\n");
	}
	else if (side == 0xcc)
	{
		size = cub->ea_t->size;
		tex = cub->ea_t->tex;

		actual_chunk = (get_decimal(ray.y) * (float)size);
		//printf("east\n");
	}
	else if (side == 0xcc00)
	{
		size = cub->we_t->size;
		tex = cub->we_t->tex;

		actual_chunk = size - (get_decimal(ray.y) * (float)size);
		//printf("west\n");
	}
	else
	{
		size = cub->black_t->size;
		tex = cub->black_t->tex;
		actual_chunk = 0;
		fog = 1;
		//printf("fog\n");
	}
	//======================================================================================//
	if (actual_chunk < 0)
		actual_chunk = 0;
	if (actual_chunk > size -1)
		actual_chunk = size - 1;
	//======================================================================================//
	while (i < HEIGHT)
	{
		j = start_x;
		k = 0;
		while (k != len)
		{
			if (i > offset_up && i < offset_down)
			{
				if (cub->cam_status == ON)
				{
					ray.color = 0x0011f752;
					if (side == 0xcc || side == 0xcc00)
						ray.color = ft_mix_color(ray.color, 0x00000000, 0.5);
					ray.color = ft_mix_color(ray.color, 0x00000000, ray.shadow);
					if (fog == 1)
						ray.color = 0;
					//======================================================================//
					//======================================================================//
					ft_put_pixel(cub->game, j, i, ray.color);
				}
				cub->screen[i][j] = ray.distance;
				wall_len += 1;
			}
			else
				cub->screen[i][j] = 30;
			k++;
			j++;
		}
		i++;
	}
	//======================================================================================//
	if (cub->cam_status == OFF)
	{
		i = 0;
		j = 0;
		real_wall_ds = ft_abs(offset_up - offset_down);
		start_point = 0;
		end_point = size;
		if (offset_up < 0)
		{
			start_point = (float)(ft_abs(offset_up) * size) / (float)real_wall_ds;
			if (offset_down > HEIGHT)
				end_point = size - ((float)(ft_abs(offset_down - HEIGHT) * size) / (float)real_wall_ds);
		}
		pixel = ft_abs2(start_point - end_point) / (float)wall_len;
		x = start_point;
		while (i < HEIGHT)
		{
			j = start_x;
			k = 0;
			while (k != len)
			{
				if (i > offset_up && i < offset_down)
				{
					if (!fog)
					{
						if (x < 0 || x >= size)
							x = size - 1;
						ray.color = tex[(int)x][actual_chunk];//here segfault
					}
					if (win)
						ray.color = ft_mix_color(0x000000FF, get_pixel_img(cub->game, j, i), 0.5);
					ray.color = ft_mix_color(ray.color, 0x00000000, ray.shadow);
					//======================================================================================//
					ft_put_pixel(cub->game, j, i, ray.color);
					//======================================================================================//
					x += pixel;
					if (x > size - 1)
						x = size - 1;
					if (x < 0)
						x = 0;
				}
				k++;
				j++;
			}
			i++;
		}
	}
	//======================================================================================//
}
