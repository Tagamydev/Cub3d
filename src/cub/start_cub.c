/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:16:18 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/04 21:59:13 by samusanc         ###   ########.fr       */
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
			ft_put_pixel(img, j++, i, color2);
		}
		i++;
	}
}

void	free_split(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free (input);
}

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
		//	printf("[%zu]", cub->map[i][j]);
			j++;
		}
		//printf("\n");
		i++;
	}
}

void	draw_direction(t_cub *cub)
{
	t_point	point1;
	t_point	point2;
	int	multiplier;

	if (cub->minimap_zoom == ZOOM_L || cub->minimap_zoom == ZOOM_S)
	{
			point1.x = 70;
		if (cub->minimap_zoom == ZOOM_S)
		{
			point1.y = 69;
			multiplier = 5;
		}
		else
		{
			point1.y = 70;
			multiplier = 100;
		}
	}
	else
	{
		point1.x = 75;
		point1.y = 75;
		multiplier = 5;
	}
	point1.z = 0;
	point1.color = 0x0000FF00;
	point2.x = point1.x + cub->player_dx * multiplier;
	point2.y = point1.y + cub->player_dy * multiplier;
	//printf("this is the delta x, y:%f, %f\n", cub->player_dx, cub->player_dy);
	point2.z = 0;
	point2.color = 0x0000FF00;
	ft_put_line(point1, point2, cub->minimap);
}

void	draw_minimark(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (i != 140)
	{
		j = 0;
		while (j != 140)
		{
			if ((i == 0 || i == 139) || (j == 0 || j == 139))
				ft_put_pixel(cub->minimap, j, i, 0x00ffffff);
			j++;
		}
		i++;
	}
}

void	draw_rays(t_cub	*cub)
{
	(void)cub;
}

void	copy_map_to_ray_map(t_cub *cub)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (i != cub->map_height)
	{
		j = 0;
		while (j != cub->map_width)
		{
			if (cub->map[i][j] == 1 || cub->map[i][j] == 6)
				cub->map_4_ray[x] = 1;
			else if ((cub->map[i][j] >= 2 && cub->map[i][j] <= 5) || cub->map[i][j] == 8)
				cub->map_4_ray[x] = 2;
			else
				cub->map_4_ray[x] = 0;
			//printf("%d, ", cub->map_4_ray[x]);
			x++;
			j++;
		}
		y++;
		i++;
	}
}

void	ray_map_draw_map(t_cub *cub)
{
	size_t		i;
	size_t		j;
	int			x;
	int			y;
	t_square	sq;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (i != cub->map_height && y != (int)cub->map_height)
	{
		x = 0;
		j = 0;
		while (i != cub->map_width && x != (int)cub->map_width)
		{
			sq.x = j;
			sq.y = i;
			sq.len = 10;
			if (cub->map[y][x] == 1)
				sq.color = 0x00FFFFFF;
			else if ((cub->map[y][x] >= 2 && cub->map[y][x] <= 5) || cub->map[y][x] == 8)
				sq.color = 0x00FF0000;
			else
				sq.color = 0x00000000;
			draw_square(cub->ray_map, sq);
			j += 10;
			x++;
		}
		y++;
		i += 10;
	}
}

void	ray_map_draw_ray(t_cub *cub, int x, int y)
{
	t_point	point1;
	t_point	point2;
	int		offset;

	offset = 10;
	point1.x = (int)cub->player_px * offset;
	point1.x += 5;
	point1.y = (int)cub->player_py * offset;
	point1.y += 5;
	point1.z = 0;
	point1.color = 0x0000ff00;
	point2.x = x * offset;
	point2.x += 5;
	point2.y = y * offset;
	point2.y += 5;
	point2.z = 0;
	point2.color = 0x0000ff00;
	ft_put_line(point1, point2, cub->ray_map);
}

void	draw_walls(t_cub *cub, float x, float y, int ray, int n_rays)
{
	int	i;
	int	j;
	int	k;
	int	start_x;
	int	len;
	double	distance;
	int		offset_up;
	int		offset_down;
	int		color_degrade;

	len = WIDTH / n_rays;
	start_x = len * ray;
	distance = sqrt(pow((x - cub->player_px), 2) + pow((y - cub->player_py), 2));
	color_degrade = ft_mix_color(0x0000FF00, 0x00000000, distance / 25);
	distance = HEIGHT - distance;
	distance = distance / 2;
	offset_up = ((HEIGHT / 2) - distance) * 10;
	offset_down = (HEIGHT - offset_up);
	i = 0;
	x = 0;
	while (i < HEIGHT)
	{
		j = start_x;
		k = 0;
		while (k != len)
		{
			if (i > offset_up && i < offset_down)
				ft_put_pixel(cub->game, j, i, color_degrade);
			k++;
			j++;
		}
		i++;
	}
	(void)x;
	(void)y;
}


void	ray_map_draw_rays(t_cub *cub)
{
	//esta basura en un palo que es un raycasting malo lo tengo que remplazar despues
	//============================================================================//
	int		rays;
	float		x;
	float		y;
	float		multiplier;
	int		divisor;
	float		angle;
	int	init;
	
	rays = 0;
	multiplier = 25;
	angle = 33;
	x = cub->player_px + (cos(cub->player_a - (DR * angle)) * SPEED) * multiplier;
	y = cub->player_py + (sin(cub->player_a - (DR * angle)) * SPEED) * multiplier;
	divisor = (angle * 2) / WIDTH;
	while (rays < WIDTH * 2)
	{
		init = 0;
		{
			x = cub->player_px + (cos(cub->player_a - (DR * angle)) * SPEED) * init;
			y = cub->player_py + (sin(cub->player_a - (DR * angle)) * SPEED) * init;
			while (cub->map[(int)y][(int)x] != 1)
			{
				x = cub->player_px + (cos(cub->player_a - (DR * angle)) * SPEED) * init;
				y = cub->player_py + (sin(cub->player_a - (DR * angle)) * SPEED) * init;
				init += 1;
			}
		}
	//==============================================================================//
	//==============================================================================//
	// esta parte ya tengo que usarla
		draw_walls(cub, x, y, rays, WIDTH);
		ray_map_draw_ray(cub, x, y);
	//==============================================================================//
	//==============================================================================//
		if (rays % 3 == 0)
			angle -= 0.2;
		rays++;
	//==============================================================================//
	}
}

void	draw_ray_map(t_cub *cub)
{
	ray_map_draw_map(cub);
	ray_map_draw_rays(cub);
}

void	start_cub(t_cub *cub)
{
	fill_img_sky_n_ground(cub->game, cub->color_sky, cub->color_ground);
	ft_fill_img(cub->minimap, 0x00000000);
	draw_minimap(cub);
	write_map(cub);
	copy_map_to_ray_map(cub);
	draw_rays(cub);
	draw_direction(cub);
	draw_minimark(cub);
	draw_ray_map(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->game->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->ray_win, cub->ray_map->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0, 0);
	return ;
	(void)cub;
}
