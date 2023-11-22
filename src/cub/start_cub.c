/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:16:18 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/22 10:14:59 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

unsigned int	get_pixel_img(t_img *img, int x, int y)
{
	return (*(unsigned int *)((img->data_addr + (y * img->line_size) + (x * img->bits_per_pixel / 8))));
}

double	angle_to_radian(double angle)
{
	return (angle * PI / 180.0);
}

double	get_decimal(double x)
{
	float	y;
	double	result;

	y = (int)x;
	result = (x * 10) - (y * 10);
	result = result / 10;
	return (result);
}

double	ft_abs2(double x)
{
	if (x < 0)
		x = -x;
	return (x);
}


double	closer_int(double n)
{
	double decimal;
	double result;

	decimal = get_decimal(n);
	if (decimal == 0.5)
	{
		while (decimal == 0.5)
			decimal = get_decimal(n * 10);
	}
	if (decimal > 0.5)
		result = (int)n + 1;
	else
		result = (int)n;
	return (result);
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
	float	m;
	int	color;

	i = 0;
	j = 0;
	m = 0;
	while (i != (img->height / 2 - 83))
	{
		j = 0;
		while (j != img->width)
		{
			color = ft_mix_color(color1, 0, m);
			ft_put_pixel(img, j, i, color);
			++j;
		}
		m += (float)1 / (float)(img->height / 2 - 83);
		i++;
	}
	float x;

	x = 0;
	while (x != 71)
	{
		color = ft_mix_color(color1, 0, m);
		j = 0;
		while (j != img->width)
		{
			color = ft_mix_color(color1, 0, m);
			ft_put_pixel(img, j, i, 0x0000FF00);
			++j;
		}
		i++;
		x++;
	}
	x = (float)1 / (float)ft_abs(HEIGHT - i);
	m = 0;
	while (i != img->height)
	{
		j = 0;
		while (j != img->width)
		{
			color = ft_mix_color(0, color2, m);
			ft_put_pixel(img, j++, i, color);
		}
		i++;
		m += x;
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
	point1.y = cub->player_py * offset;
	point1.z = 0;
	point1.color = color;
	point2.x = x * offset;
	point2.y = y * offset;
	point2.z = 0;
	point2.color = color;
	ft_put_line(point1, point2, cub->ray_map);
	ft_put_pixel(cub->ray_map, point1.x, point1.y, color);
}

int	tex[16][16] = {\
	{0x00FF0000, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0x0000FF00}, \
	{0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF}, \
	{0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0}, \
	{0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF}, \
	{0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0}, \
	{0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF}, \
	{0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0}, \
	{0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FFFFFF}, \
	{0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0}, \
	{0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF}, \
	{0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0}, \
	{0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF}, \
	{0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0}, \
	{0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF}, \
	{0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0}, \
	{0x000000FF, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF, 0, 0x00FFFFFF}};


void	draw_walls(t_cub *cub, t_ray ray, size_t actual_ray, size_t total_rays, int side)
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
	int		fog;
	size_t	wall_len;
	int		actual_chunk;
	int		size;

	i = 0;
	fog = 0;
	len = WIDTH / total_rays;
	start_x = len * actual_ray;
	distance = (240 * 15) / ray.distance;
	distance = distance / 5;
	offset_up = ((HEIGHT / 2.5) - distance);
	offset_down = (HEIGHT / 1.25 - offset_up);
	color_ground_mix = 0;
	wall_len = 0;
	size = 16;
	if (side == 0x00FF0000)
	{
		actual_chunk = size - (get_decimal(ray.x) * (float)size);
		//printf("south\n");
	}
	else if (side == 0x00FF00FF)
	{
		actual_chunk = (get_decimal(ray.x) * (float)size);
		//printf("north\n");
	}
	else if (side == 0xcc)
	{
		actual_chunk = (get_decimal(ray.y) * (float)size);
		//printf("east\n");
	}
	else if (side == 0xcc00)
	{
		actual_chunk = size - (get_decimal(ray.y) * (float)size);
		//printf("west\n");
	}
	else
	{
		actual_chunk = 0;
		fog = 1;
		//printf("fog\n");
	}
	if (actual_chunk < 0)
		actual_chunk = 0;
	if (actual_chunk > size -1)
		actual_chunk = size - 1;
	while (i < HEIGHT)
	{
		j = start_x;
		k = 0;
		while (k != len)
		{
			if (i > offset_up && i < offset_down)
				wall_len += 1;
			k++;
			j++;
		}
		i++;
	}
	float pixel;
	float	start_point;
	float	end_point;
	int		real_wall_ds;
	float	x;

	i = 0;
	j = 0;
	real_wall_ds = ft_abs(offset_up - offset_down);
	start_point = 0;
	end_point = size;
	if (offset_up < 0)
	{
		start_point = (float)(ft_abs(offset_up) * 16) / (float)real_wall_ds;
		if (offset_down > HEIGHT)
		{
			end_point = size - ((float)(ft_abs(offset_down - HEIGHT) * 16) / (float)real_wall_ds);
		}
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
					ray.color = tex[(int)x][actual_chunk];
				ray.color = ft_mix_color(ray.color, 0x00000000, ray.shadow);
				ft_put_pixel(cub->game, j, i, ray.color);
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
	(void)cub;
}

//==============================================================================//
//==============================================================================//

t_tex	new_text()
{
	t_tex hola;
	hola.size = 1;
	return (hola);
}

//==============================================================================//
//==============================================================================//
t_p	default_ray(t_cub *cub)
{
	t_p		result;

	result.x = cub->player_px;
	result.y = cub->player_py;
	return (result);
}

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

t_ray	calculate_ray(t_ray tmp_ray, t_cub *cub, int color)
{
	t_ray	result;
	t_p		cam_plane;
	float	shadow;

	result = tmp_ray;
	cam_plane = calculate_cam_plane(result, cub);
	result.distance = sqrt(pow((result.x - cam_plane.x), 2) + \
	pow((result.y - cam_plane.y), 2));
	shadow = result.distance / 21;
	if (shadow >= 1)
		shadow = 1;
	result.color = color;
	result.shadow = shadow;
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

t_p	ray_to_point(t_ray ray)
{
	t_p	result;

	result.x = ray.x;
	result.y = ray.y;
	result.dx = cos(angle_to_radian(get_angle(ray.angle))) * 3;
	result.dy = sin(angle_to_radian(get_angle(ray.angle))) * 3;
	return (result);
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
double	ft_ds(double xi, double xf, double yi, double yf)
{
	double	result;

	result = sqrt(pow((xi - xf), 2) + \
	pow((yi - yf), 2));
	return (result);
}

#define FRONT 1
#define SIDE 0

int	get_next_status(t_cub *cub, float ray_a, float *ds, int m, float last_distance)
{
	double		x;
	double		y;
	double		ray_dx;
	double		ray_dy;
	float		ray_proyection;
	int			status1;

	ray_proyection = 0;
	ray_dx = cos(angle_to_radian(get_angle(ray_a)));
	ray_dy = sin(angle_to_radian(get_angle(ray_a)));
	x = cub->player_px + ray_dx * 0;
	y = cub->player_py + ray_dy * 0;
	while (cub->map[(int)y][(int)x] != 1 && cub->map[(int)y][(int)x] != 6)
	{
		x = x + ray_dx * ray_proyection;
		y = y + ray_dy * ray_proyection;
		if (last_distance > 1)
			ray_proyection += 0.0001;
		else
			ray_proyection += 0.001;
	}
	if (ft_abs2(closer_int(y) - y) > ft_abs2(closer_int(x) - x))
		status1 = SIDE;
	else
		status1 = FRONT;
	*ds = ft_ds(cub->player_px, x, cub->player_py, y);
	if (ft_abs2(closer_int(y) - y) < 0.09 && ft_abs2(closer_int(x) - x) < 0.09)
	{
		if (ft_abs2(last_distance - ft_ds(cub->player_px, x, cub->player_py, y) < 1))
			status1 = get_next_status(cub, ray_a + (0.046948 * m), ds, m, *ds);
	}
	return (status1);
}

float	ft_fit_char(float n, float min, float max)
{
	float	range;
	float	result;

	range = ft_abs2(min - max);
	result = (float)(n * range) / (float)(255);
	return (result);
}

float	ft_random(float n, float min, float max)
{
	int				i;
	size_t			j;
	int				fd;
	static int		decimals;
	static double	result = 7;

	fd = open("/dev/urandom", O_RDONLY);
	i = 0;
	j = 0;
	while (j < (size_t)n)
	{
		decimals = i;
		read(fd, &i, 1);
		j++;
	}
	result = ft_fit_char(decimals, 0, 1);
	result = ft_fit_char((float)i + result, min, max);
	close(fd);
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

	int			status1;
	int			color2;
	int			last_status = SIDE;
	double		last_distance;
	float		fogxf;
	float		fogyf;
	float		fog_ds;
	float		actual_ds;

	ray_dx = 0;
	ray_dy = 0;
	x = (double)cub->player_px;
	y = (double)cub->player_py;
	ray = 0;
	ray_proyection = 0;
	anglei = 0;
	angle = 30;
	angle_chunk = 0.046948;
	angle_chunk = angle_chunk * 3;
	last_distance = INT_MAX;
	while (ray < WIDTH / 3)
	{
		//ray_a = get_angle(cub->player_a);//cub->player_a + anglei - (angle / 2);
		ray_a = cub->player_a + anglei - (angle / 2);
		ray_dx = cos(angle_to_radian(get_angle(ray_a)));
		ray_dy = sin(angle_to_radian(get_angle(ray_a)));
		fogxf = cub->player_px + cos(angle_to_radian(get_angle(ray_a))) * 20;
		fogyf = cub->player_py + sin(angle_to_radian(get_angle(ray_a))) * 20;
		fog_ds = ft_ds(cub->player_px, fogxf, cub->player_py, fogyf);
		ray_proyection = 0;
		x = cub->player_px + ray_dx * 0;
		y = cub->player_py + ray_dy * 0;
		while (cub->map[(int)y][(int)x] != 1 && cub->map[(int)y][(int)x] != 6)
		{
			x = x + ray_dx * ray_proyection;
			y = y + ray_dy * ray_proyection;
			actual_ds = ft_ds(cub->player_px, x, cub->player_py, y);
			if (actual_ds > fog_ds)
				break;
			ray_proyection += 0.0001;
		}
		ray_map_draw_ray(cub, x, y, 0x00FFFF06);//draw rays in minimap
		/*
		if ((int)(ray_a * 10) == (int)(cub->player_a * 10))
			printf("distance:%f\n", actual_ds);
			*/
		if (actual_ds < fog_ds)
		{
			if (ft_abs2(closer_int(y) - y) > ft_abs2(closer_int(x) - x))
				status1 = SIDE;
			else
				status1 = FRONT;
			if (ft_abs2(closer_int(y) - y) < 0.09 && ft_abs2(closer_int(x) - x) < 0.09)
			{
				if (ft_abs2(last_distance - ft_ds(cub->player_px, x, cub->player_py, y) < 1))
				{
					float	after_distance;
					float	before_distance;
					float	actual_distance;
					int		after_status;
					int		before_status;
	
					actual_distance = ft_ds(cub->player_px, x, cub->player_py, y);
					after_status = get_next_status(cub, ray_a, &after_distance, 1, last_distance);
					before_status = get_next_status(cub, ray_a, &before_distance, -1, last_distance);
					before_distance = ft_abs2(before_distance - actual_distance);
					after_distance = ft_abs2(after_distance - actual_distance);
					if (after_distance < before_distance)
						status1 = after_status;
					else
						status1 = before_status;
				}
				else
					status1 = 4;
			}
		}
		else
		{
			status1 = 5;
		}

		last_status = status1;

		if (status1 == SIDE)
		{
			if (get_angle(ray_a) < 270 && get_angle(ray_a) > 90)
				color2 = 0x0000FF00;//draw rays in minimap
			else
				color2 = 0x000000FF;//draw rays in minimap
			color2 = ft_mix_color(color2, 0x00000000, 0.2);
		}
		else if (status1 == FRONT)
		{
			if (get_angle(ray_a) < 180 && get_angle(ray_a) > 0)
				color2 = 0x00FF0000;//draw rays in minimap
			else
				color2 = 0x00ff00ff;//draw rays in minimap
		}
		else if (status1 == 4)
				color2 = 0;//draw rays in minimap
		else
				color2 = ft_mix_color(cub->color_sky, 0, 0.10);
		last_distance = ft_ds(cub->player_px, x, cub->player_py, y);
		draw_walls(cub, calculate_ray(make_tmp_ray(x, y, ray_a, cub), cub, color2), ray, WIDTH / 3, color2);//draw walls
		//draw_walls(cub, calculate_ray(make_tmp_ray(x, y, ray_a, cub), cub, color2), ray, 1, color2);//draw walls
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
	float	h;

	h = HEIGHT / 1.3;
	point1.z = 0;
	point2.z = 0;
	point1.color = 0x00FFFFFF;
	point2.color = 0x00FFFFFF;
	point1.x = (WIDTH / 2) - 10;
	point1.y = h / 2;
	point2.x = (WIDTH / 2) + 10;
	point2.y = h / 2;
	ft_put_line(point1, point2, cub->game);
	point1.x = (WIDTH / 2);
	point1.y = (h / 2) - 10;
	point2.x = (WIDTH / 2);
	point2.y = (h / 2) + 10;
	ft_put_line(point1, point2, cub->game);
}

t_win	tmp_win(void *mlx, void *win, t_img *result)
{
	t_win	final;

	final.mlx = mlx;
	final.win = win;
	final.result = result;
	return (final);
}

void	put_img_win(t_img img, t_win win, int x, int y)
{
	(void)img;
	(void)win;
	(void)x;
	(void)y;
}

//write_map(cub);
void	start_cub(t_cub *cub)
{
	fill_img_sky_n_ground(cub->game, cub->color_sky, cub->color_ground);
	ft_fill_img(cub->minimap, 0x00000000);
	ft_fill_img(cub->atm, ft_mix_color(ft_mix_color(cub->color_sky, cub->color_ground, 0.5), 0xFF000000, 0.60));
	draw_minimap(cub);
	copy_map_to_ray_map(cub);
	draw_rays(cub);
	draw_direction(cub);
	draw_minimark(cub);
	draw_ray_map(cub);
	draw_cross(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->game->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->atm->img, 0, 0);
	if (cub->door == 1)
	{
		printf("%f\n", ft_random(1, 0, 1));
		mlx_put_image_to_window(cub->mlx, cub->win, cub->hud_o->img, 0, 0);
	}
	else
	{
		mlx_put_image_to_window(cub->mlx, cub->win, cub->hud_c->img, 0, 0);
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 13, 8);
	mlx_put_image_to_window(cub->mlx, cub->ray_win, cub->ray_map->img, 0, 0);
	return ;
	(void)cub;
}
