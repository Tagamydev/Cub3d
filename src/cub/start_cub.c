/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:16:18 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/08 14:13:05 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

double	angle_to_radian(double angle)
{
	return (angle * PI / 180.0);
}

double	get_angle(double angle)
{
	if (angle > 59)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	return (angle);
}

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
			printf("[%zu]", cub->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	draw_direction(t_cub *cub)
{
	//====================================THIS NEED REWORK=============================================//
	t_point	point1;
	t_point	point2;
	int	multiplier;

	if (cub->minimap_zoom == ZOOM_L || cub->minimap_zoom == ZOOM_S)
	{
			point1.x = 70;
		if (cub->minimap_zoom == ZOOM_S)
		{
			point1.y = 69;
			multiplier = 100;
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
		multiplier = 100;
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
				sq.color = 0x00000000;
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

void	ray_map_draw_ray(t_cub *cub, float x, float y, int color)
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
	point1.color = color;
	point2.x = x * offset;
	point2.y = y * offset;
	point2.z = 0;
	point2.color = color;
	ft_put_line(point1, point2, cub->ray_map);
	ft_put_pixel(cub->ray_map, point1.x, point1.y, color);
}

	/*
	int	i;
	int	j;
	int	k;
	int	start_x;
	int	len;
	double	distance;
	int		offset_up;
	int		offset_down;
	int		color_degrade;
	float	color_ground_mix;
	int	side;
	float	fish;

	side = 0;
	len = WIDTH / n_rays;
	start_x = len * ray;
	distance = sqrt(pow((x - cub->player_px), 2) + pow((y - cub->player_py), 2));
	fish = distance * 0.5;

	color_degrade = ft_mix_color(0x0000FF00, 0x00000000, distance / 50);
	if (side)
		color_degrade = ft_mix_color(0x0000FF00, 0x00000000, 1);
	color_degrade = ft_mix_color(color_degrade, cub->color_sky, 0.25);
	distance = HEIGHT - distance;
	distance = distance / 2;
	offset_up = ((HEIGHT / 2) - distance) * fish;
	offset_down = (HEIGHT - offset_up);
	i = 0;
	x = 0;
	color_ground_mix = 0;
	while (i < HEIGHT)
	{
		j = start_x;
		k = 0;
		while (k != len)
		{
			if (i > offset_up && i < offset_down)
			{
				if (i > offset_down / 1.2)
				{
					color_degrade = ft_mix_color(color_degrade, cub->color_ground, color_ground_mix);
					color_ground_mix += 0.00001;
				}
				ft_put_pixel(cub->game, j, i, color_degrade);
			}
			k++;
			j++;
		}
		i++;
	}
	*/
void	draw_walls(t_cub *cub, t_ray ray, size_t actual_ray, size_t total_rays)
{
	int		i;
	int		j;
	int		k;
	int		start_x;
	int		len;
	int		offset_up;
	int		offset_down;
	float	color_ground_mix;
	double	distance;

	i = 0;
	len = WIDTH / total_rays;
	start_x = len * actual_ray;
	distance = HEIGHT - ray.distance;
	distance = distance / 2;
	offset_up = ((HEIGHT / 2) - distance) * 15;
	offset_down = (HEIGHT - offset_up);
	color_ground_mix = 0;
	while (i < HEIGHT)
	{
		j = start_x;
		k = 0;
		while (k != len)
		{
			if (i > offset_up && i < offset_down)
				ft_put_pixel(cub->game, j, i, ray.color);
			k++;
			j++;
		}
		i++;
	}
}

t_p	calculate_cam_plane(t_ray ray, t_cub *cub)
{
	t_p	result;
	t_p	multiplier;
	int	side;
	float	angle;

	if (ray.angle == cub->player_a || cub->fisheye == 1)
	{
		result.x = cub->player_px;
		result.y = cub->player_py;
		return (result);
	}

	//==========================//
	
	if (ray.angle > cub->player_a)
		side = 1;
	else
		side = -1;

	angle = 180;
	angle *= side;
	angle += cub->player_a;
	result.x = ray.x;
	result.y = ray.y;
	result = make_point_with_dir(ray.x, ray.y, \
			cos(angle_to_radian(get_angle(angle))), \
			sin(angle_to_radian(get_angle(angle))));
	multiplier = make_point_with_dir(cub->player_px, \
			cub->player_py, \
			cub->player_d2x * side, \
			cub->player_d2y * side);
	result = intersection_btw_points(result, multiplier);
	if (result.x == result.x && result.y == result.y)
	{
		;
	}
	else
	{
		result.x = cub->player_px;
		result.y = cub->player_py;
		return (result);
	}

	//multiplier.x += multiplier.dx * 10;
	//multiplier.y += multiplier.dy * 10;
	//result = multiplier;

	/*
	t_point	point1;
	t_point	point2;
	int		offset;
	int		color = 0x000000ff;

	offset = 10;
	point1.x = ray.x * 10;
	point1.y = ray.y * 10;
	point1.z = 0;
	point1.color = color;
	point2.x = result.x * offset;
	point2.y = result.y * offset;
	point2.z = 0;
	point2.color = 0x00FFFFFF;





	//ray_map_draw_ray(cub, result.x, result.y, 0x00FF0000);
	ft_put_line(point1, point2, cub->ray_map);



	//if (ray.angle == cub->player_a)
	{
		result.x = cub->player_px;
		result.y = cub->player_py;
		return (result);
	}

	*/
	return (result);
}

t_ray	calculate_ray(float x, float y, float angle, t_cub *cub)
{
	t_ray	result;
	t_p		cam_plane;

	result.x =  x;
	result.y =  y;
	result.angle = angle;
	cam_plane = calculate_cam_plane(result, cub);
	result.distance = sqrt(pow((x - cam_plane.x), 2) + \
	pow((y - cam_plane.y), 2));
	result.color = ft_mix_color(0x0000FF00, 0x00000000, result.distance / 50);
	//result.color = ft_mix_color(result.color, cub->color_sky, 0.25);
	return (result);
}

double	calculate_next_wall(float x, float y, float angle)
{
	(void)x;
	(void)y;
	(void)angle;
	return (0);
}
	/*
	int			ray;
	int			angle;
	double		x;
	double		y;
	double		ray_dx;
	double		ray_dy;
	double		anglei;
	double		angle_chunk;
	double		ray_a;
	float		multiplier;
	int			side;

	ray = 0;
	ray_dx = 0;
	ray_dy = 0;
	anglei = 0;
	angle = 30;
	angle_chunk = 0.046875 * 2;
	multiplier = 0;
	side = 0;
	while (ray < WIDTH)
	{
		ray_a = get_angle((cub->player_a - angle) + anglei);
		ray_dx = cos(angle_to_radian(get_angle(ray_a)));
		ray_dy = sin(angle_to_radian(get_angle(ray_a)));
		x = cub->player_px + ray_dx * multiplier;
		y = cub->player_py + ray_dy * multiplier;
		//==============================================================//
		while (x < cub->map_width && y < cub->map_height && x > 0 && y > 0)
		{
			if (cub->map[(int)y][(int)x] == 1)
				break ;
			x = cub->player_px + ray_dx * multiplier;
			y = cub->player_py + ray_dy * multiplier;
			multiplier += 0.0001;
		}
		//==============================================================//
		draw_walls(cub, calculate_ray(x, y, ray_a, cub), ray, WIDTH);
		ray_map_draw_ray(cub, x, y);
		anglei += angle_chunk;
		ray++;
	}
	(void)cub;
	*/

void	ray_map_draw_rays(t_cub *cub)
{
	int			ray;
	double		x;
	double		y;
	double		ray_dx;
	double		ray_dy;
	float		ray_a;
	float		ray_proyection;
	int			angle;
	double		angle_chunk;
	double		anglei;

	ray_dx = 0;
	ray_dy = 0;
	x = (double)cub->player_px;
	y = (double)cub->player_py;
	ray = 0;
	ray_proyection = 0;
	anglei = 0;
	angle = 30;
	angle_chunk = 0.058;
	while (ray < WIDTH)
	{
		ray_a = /*cub->player_a;*/cub->player_a + anglei - (angle / 2);
		ray_proyection = 0;
		ray_dx = cos(angle_to_radian(get_angle(ray_a)));
		ray_dy = sin(angle_to_radian(get_angle(ray_a)));
		x = cub->player_px + ray_dx * 1;
		y = cub->player_py + ray_dy * 1;
		while (cub->map[(int)y][(int)x] != 1 && cub->map[(int)y][(int)x] != 6)
		{
			x = cub->player_px + ray_dx * ray_proyection;
			y = cub->player_py + ray_dy * ray_proyection;
			ray_proyection += 0.01;
		}
		draw_walls(cub, calculate_ray(x, y, ray_a, cub), ray, WIDTH);
		ray_map_draw_ray(cub, x, y, 0x0000FF00);
		anglei += angle_chunk;
		ray++;
	}
	(void)cub;
}

void	draw_ray_map(t_cub *cub)
{
	ray_map_draw_map(cub);
	ray_map_draw_rays(cub);
}

void	draw_cross(t_cub *cub)
{
	t_point	point1;
	t_point	point2;

	point1.z = 0;
	point2.z = 0;
	point1.color = 0x00FFFFFF;
	point2.color = 0x00FFFFFF;
	//=============================//
	point1.x = (WIDTH / 2) - 10;
	point1.y = HEIGHT / 2;
	point2.x = (WIDTH / 2) + 10;
	point2.y = HEIGHT / 2;
	ft_put_line(point1, point2, cub->game);
	point1.x = (WIDTH / 2);
	point1.y = (HEIGHT / 2) - 10;
	point2.x = (WIDTH / 2);
	point2.y = (HEIGHT / 2) + 10;
	ft_put_line(point1, point2, cub->game);
}

//write_map(cub);
void	start_cub(t_cub *cub)
{
	fill_img_sky_n_ground(cub->game, cub->color_sky, cub->color_ground);
	ft_fill_img(cub->minimap, 0x00000000);
	draw_minimap(cub);
	copy_map_to_ray_map(cub);
	draw_rays(cub);
	draw_direction(cub);
	draw_minimark(cub);
	draw_ray_map(cub);
	draw_cross(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->game->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->ray_win, cub->ray_map->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0, 0);
	return ;
	(void)cub;
}
