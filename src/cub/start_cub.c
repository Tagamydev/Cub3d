/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:16:18 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/13 10:22:34 by samusanc         ###   ########.fr       */
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
			ft_put_pixel(cub->ray_map, j, i, 0x00ffffff);
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
	point1.x = cub->player_px * offset;
	//point1.x += 5;
	point1.y = cub->player_py * offset;
	//point1.y += 5;
	point1.z = 0;
	point1.color = color;
	point2.x = x * offset;
	point2.y = y * offset;
	point2.z = 0;
	point2.color = color;
	ft_put_line(point1, point2, cub->ray_map);
	ft_put_pixel(cub->ray_map, point1.x, point1.y, color);
}

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

t_p	default_ray(t_cub *cub)
{
	t_p		result;

	result.x = cub->player_px;
	result.y = cub->player_py;
	return (result);
}

/*
	con esto puedes hacer angulos de la camara!!
*/
t_p	calculate_cam_plane(t_ray ray, t_cub *cub)
{
	t_p		result;
	t_p		multiplier;
	float	angle;

	if (ray.angle == cub->player_a || cub->fisheye == 1)
		return (default_ray(cub));
	angle = 180;
	angle *= ray.side;
	angle += cub->player_a;
	result.x = ray.x;
	result.y = ray.y;
	result = make_point_with_dir(ray.x, ray.y, \
			cos(angle_to_radian(get_angle(angle))), \
			sin(angle_to_radian(get_angle(angle))));
	multiplier = make_point_with_dir(cub->player_px, \
			cub->player_py, \
			cub->player_d2x * ray.side, \
			cub->player_d2y * ray.side);
	result = intersection_btw_points(result, multiplier);
	if (result.x != result.x || result.y != result.y)
		return (default_ray(cub));
	return (result);
}

t_ray	calculate_ray(t_ray tmp_ray, t_cub *cub)
{
	t_ray	result;
	t_p		cam_plane;

	result = tmp_ray;
	cam_plane = calculate_cam_plane(result, cub);
	result.distance = sqrt(pow((result.x - cam_plane.x), 2) + \
	pow((result.y - cam_plane.y), 2));
	result.color = ft_mix_color(0x0000FF00, 0x00000000, result.distance / 50);
	result.color = ft_mix_color(result.color, cub->color_sky, 0.25);
	return (result);
}

t_ray	make_tmp_ray(float x, float y, float angle, t_cub *cub)
{
	t_ray	result;

	result.x =  x;
	result.y =  y;
	result.angle = angle;
	if (result.angle > cub->player_a)
		result.side = 1;
	else
		result.side = -1;
	return (result);
}
//quadrant_1();
//quadrant_2();
//quadrant_3();
//quadrant_4();

//upper_vertical_line();
//lower_vertical_line();
//lower_horizontal_line();
//upper_horizontal_line();

t_p	ray_to_point(t_ray ray)
{
	t_p	result;

	result.x = ray.x;
	result.y = ray.y;
	result.dx = cos(angle_to_radian(get_angle(ray.angle))) * 3;
	result.dy = sin(angle_to_radian(get_angle(ray.angle))) * 3;
	return (result);

	//point1.x += 5;
	//point1.y += 5;

}
void	ft_line(float x1, float y1, float x2, float y2, t_cub *cub, int color)
{
	t_point	point1;
	t_point	point2;
	int		offset;

	offset = 10;
	point1.x = x1 * offset;
	point1.y = y1 * offset;
	point1.z = 0;
	point1.color = color;
	point2.x = x2 * offset;
	point2.y = y2 * offset;
	point2.z = 0;
	point2.color = color;
	ft_put_line(point1, point2, cub->ray_map);
}

double	ft_abs2(double x)
{
	if (x < 0)
		x = -x;
	return (x);
}

double	get_decimal(double x)
{
	float	y;
	double	result;

	y = (int)x;
	result = (x * 10) - (y * 10);
	return (result);
}

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
		ray_a = /*get_angle(cub->player_a);*/cub->player_a + anglei - (angle / 2);
		ray_dx = cos(angle_to_radian(get_angle(ray_a)));
		ray_dy = sin(angle_to_radian(get_angle(ray_a)));
		ray_proyection = 0;
		x = cub->player_px + ray_dx * 0;
		y = cub->player_py + ray_dy * 0;
		while (cub->map[(int)y][(int)x] != 1 && cub->map[(int)y][(int)x] != 6)
		{
			x = x + ray_dx * ray_proyection;
			y = y + ray_dy * ray_proyection;
			ray_proyection += 0.0001;
		}
		draw_walls(cub, calculate_ray(make_tmp_ray(x, y, ray_a, cub), cub), ray, WIDTH);//draw walls
		if (get_decimal(x) < get_decimal(y))
			ray_map_draw_ray(cub, x, y, 0x0000FF00);//draw rays in minimap
		else
			ray_map_draw_ray(cub, x, y, 0x00FF0000);//draw rays in minimap
		printf("x:%f, y:%f\n", get_decimal(x), get_decimal(y));
		printf("x:%f, y:%f\n\n", x, y);
		//ray_map_draw_ray(cub, x, y, 0x0000FF00);//draw rays in minimap
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
