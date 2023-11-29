/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:16:18 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/29 15:11:13 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	get_pixel_img(t_img *img, int x, int y)
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

float	ft_fit_char(float n, float min, float max)
{
	float	range;
	float	result;

	range = ft_abs2(min - max);
	result = (float)(n * range) / (float)(255);
	result += min;
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
	while (j < 3)
	{
		decimals = i;
		read(fd, &i, 1);
		j++;
	}
	result = ft_fit_char(decimals, 0, 1);
	result = ft_fit_char((float)i + result, min, max);
	close(fd);
	(void)n;
	return (result);
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

double	get_opacity(int color)
{
	int		bite;
	double	result;

	bite = ((color >> 24) & 0xFF);
	result = ft_fit_char(bite, 0, 1);
	return (result);
}

int		get_flat_color(int color)
{
	int r;
	int g;
	int b;
	int t;

	t = 0;
	r = ((color >> 16) & 0xFF);
	g = ((color >> 8) & 0xFF);
	b = ((color) & 0xFF);
	return (t << 24 | r << 16 | g << 8 | b);
}

void	make_img_translucent(t_img *img, double o)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color = get_pixel_img(img, x, y);
			color = ft_mix_color(color, 0xFF000000, o);
			ft_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

double	get_angle(double angle)
{
	if (angle > 59)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	return (angle);
}

void	fill_img_sky_n_ground(t_img *img, int color1, int color2, int status)
{
	int	i;
	int	j;
	float	m;
	int	color;
	float x;

	i = 0;
	j = 0;
	m = 0;
	int cam;
	int ground;
	if (status == OFF)
	{
		cam = 83;
		ground = 12;
	}
	else
	{
		cam = 71;
		ground = 24;
	}
	while (i != (img->height / 2 - cam))
	{
		j = 0;
		while (j != img->width)
		{
			color = ft_mix_color(color1, 0, m);
			ft_put_pixel(img, j, i, color);
			++j;
		}
		m += (float)1 / (float)(img->height / 2 - cam);
		i++;
	}
	x = 0;
	while (x != cam - ground)
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

t_tex	new_text()
{
	t_tex hola;
	hola.size = 1;
	return (hola);
}

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
	if (cub->cam_status == OFF)
		shadow = 17;
	else
		shadow = 30;
	shadow = result.distance / shadow;
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

double	ft_ds(double xi, double xf, double yi, double yf)
{
	double	result;

	result = sqrt(pow((xi - xf), 2) + \
	pow((yi - yf), 2));
	return (result);
}

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
	while (cub->map[(int)y][(int)x] != 1)
	{
		x = x + ray_dx * ray_proyection;
		y = y + ray_dy * ray_proyection;
		ray_proyection += 0.0001;
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

void	ray_map_draw_rays(t_cub *cub)
{
	static int	last_status = SIDE;
	double		x;
	double		y;
	double		anglei;
	double		ray_dx;
	double		ray_dy;
	double		angle_chunk;
	double		last_distance;
	float		fogxf;
	float		fogyf;
	float		fog_ds;
	float		actual_ds;
	float		winx;
	float		winy;
	float		ray_a;
	float		ray_proyection;
	int			ray;
	int			angle;
	int			color2;
	int			status1;
	int			chunks;
	int			win;

	//=============================================================================================//
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
	if (cub->cam_status == OFF)
		chunks = 20;
	else
		chunks = 30;
	//=============================================================================================//
	while (ray < WIDTH / 3)
	{
		//=============================================================================================//
		win = 0;
		winx = cub->player_px;
		winy = cub->player_py;
		ray_a = cub->player_a + anglei - (angle / 2);
		ray_dx = cos(angle_to_radian(get_angle(ray_a)));
		ray_dy = sin(angle_to_radian(get_angle(ray_a)));
		fogxf = cub->player_px + cos(angle_to_radian(get_angle(ray_a))) * chunks;
		fogyf = cub->player_py + sin(angle_to_radian(get_angle(ray_a))) * chunks;
		fog_ds = ft_ds(cub->player_px, fogxf, cub->player_py, fogyf);
		ray_proyection = 0;
		x = cub->player_px + ray_dx * 0;
		y = cub->player_py + ray_dy * 0;
		//=============================================================================================//
		while (cub->map[(int)y][(int)x] != 1)
		{
			if (cub->map[(int)y][(int)x] == 6 && winx == cub->player_px && winy == cub->player_py)
			{
				win = 1;
				winx = x;
				winy = y;
			}
			x = x + ray_dx * ray_proyection;
			y = y + ray_dy * ray_proyection;
			actual_ds = ft_ds(cub->player_px, x, cub->player_py, y);
			if (actual_ds > fog_ds)
				break;
			ray_proyection += 0.0001;
		}
		//=============================================================================================//
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
				//==============================================================================//
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
				//==============================================================================//
				}
				else
					status1 = 4;
			}
		}
		else
			status1 = 5;
		last_status = status1;
		//=============================================================================================//
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
		//=============================================================================================//
		last_distance = ft_ds(cub->player_px, x, cub->player_py, y);
		draw_walls(cub, calculate_ray(make_tmp_ray(x, y, ray_a, cub), cub, color2), ray, WIDTH / 3, color2, 0);
		if (win == 1)
			draw_walls(cub, \
			calculate_ray(make_tmp_ray(winx, winy, ray_a, cub), \
			cub, color2), ray, WIDTH / 3, color2, 1);
		//=============================================================================================//
		anglei += angle_chunk;
		ray++;
	}
	(void)cub;
}

void	draw_ray_map(t_cub *cub)
{
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

void	put_noise(t_cub *cub)
{
	static int last_noise = 0;
	int	noise;

	noise = ft_random(1, 1, 7);
	while (noise == last_noise)
		noise = ft_random(1, 1, 7);
	last_noise = noise;
	if (noise == 1)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->noise1->img, 0, 0);
	else if (noise == 2)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->noise2->img, 0, 0);
	else if (noise == 3)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->noise3->img, 0, 0);
	else if (noise == 4)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->noise4->img, 0, 0);
	else if (noise == 5)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->noise5->img, 0, 0);
	else
		mlx_put_image_to_window(cub->mlx, cub->win, cub->noise6->img, 0, 0);
}

void	ray_caster(t_cub *cub)
{
	draw_minimap(cub);
	draw_direction(cub);
	draw_minimark(cub);
	draw_ray_map(cub);
	draw_cross(cub);
}

void	sprites(t_cub *cub, float sx, float sy, t_tex *tex)
{
	float	x;
	float	y;
	float	angle;
	float	angle2;
	float	up;
	float	down;
	float	screenx;
	float	ds;
	float	distance;
	float	offset_up;
	float	offset_down;
	float	offset_left;
	float	offset_right;
	float	offup;
	float	offdo;
	float	offset;
	float	chunk;
	float	offl;
	float	offr;
	float	txt_i;
	float	txt_f;
	float	y2;
	float	new_size;
	float	start_point;
	float	end_point;
	float	real_wall_ds;
	float	z;
	float	chunk2;
	int		side;
	int		i;
	int		j;
	int		r_wall_len;
	int		k;
	int		initial;
	int		final;
	int		size;
	int		color;
	int		tmp;
	float		tmp1;
	size_t	wall_len;

	//=========================================================//
	sx += 0.5;
	sy += 0.5;
	if (cub->player_py - sy < 0)
		side = -1;
	else
		side = 1;
	ds = ft_ds(sx, cub->player_px, sy, cub->player_py);
	up = sx - cub->player_px;
	down = ds;
	angle = acos(up / down) * 180.0 / PI;
	angle *= side;
	if (cub->player_a > 180)
		angle2 = cub->player_a - 360;
	else
		angle2 = cub->player_a;
	angle = angle2 + angle;
	angle *= -1;
	angle += 15;
	screenx = (angle * WIDTH) / (float)30;
	//===================================================================//
	wall_len = 0;
	distance = (240 * 15) / ds;
	distance = distance / 5;
	offset_up = ((HEIGHT / 2.5) - distance);
	offset_down = (HEIGHT / 1.25 - offset_up);
	i = 0;
	while (i < HEIGHT)
	{
		j = screenx;
		if (i > offset_up && i < offset_down)
			wall_len += 1;
		i++;
	}
	//===================================================================//
	offset_left = 0;
	offset_right = 0;
	if (screenx < 0)
		offset_left = screenx * (-1);
	if (screenx > WIDTH)
		offset_right = screenx - WIDTH;
	r_wall_len = ft_abs(offset_up - offset_down);
	if (offset_left > r_wall_len || offset_right > r_wall_len)
		return ;
	//===================================================================//
	i = 0;
	size = tex->size;
	if (offset_up < 0)
		offup = (float)ft_abs(offset_up) / (float)HEIGHT;
	else
		offup = 0;
	if (offset_down > HEIGHT)
		offdo = (float)ft_abs(offset_down - HEIGHT) / (float)HEIGHT;
	else
		offdo = 0;
	offset = (offup) * ((float)r_wall_len);
	initial = screenx - ((float)(r_wall_len) / (float)2.35);
	chunk = (r_wall_len * 0.85);
	final = initial + chunk;
	//===================================================================//
	y = 0;
	start_point = 0;
	end_point = size;
	start_point = 0;
	end_point = size;
	real_wall_ds = ft_abs(offset_up - offset_down);
	if (offset_up < 0)
	{
		start_point = (float)(ft_abs(offset_up) * size) / (float)real_wall_ds;
		if (offset_down > HEIGHT)
			end_point = size - ((float)(ft_abs(offset_down - HEIGHT) * size) / (float)real_wall_ds);
	}
	new_size = ft_abs2(start_point - end_point);
	//===================================================================//
	if (initial < 0)
		offl = ft_abs(initial);
	else
		offl = 0;
	if (final > 640)
		offr = final - WIDTH;
	else
		offr = 0;
	txt_i = (float)(ft_abs(offl) * new_size) / chunk;
	if (txt_i < 0)
		txt_i = 0;
	if (txt_i > size - 1)
		txt_i = size - 1;
	txt_f = size - (float)(ft_abs(offr) * new_size) / chunk;
	if (txt_f < 0)
		txt_f = 0;
	if (txt_f > size - 1)
		txt_f = size - 1;
	z = 0;
	x = 0;
	y = 0;
	chunk = (float)(ft_abs2(txt_i - txt_f)) / (float)(r_wall_len * 0.85);
	chunk2 = 1;
	int	translucid;
	//===================================================================//
	while (i < HEIGHT)
	{
		x = txt_i;
		j = initial;
		k = 0;
		if (i > offset_up && i < offset_down)
			y++;
		while (k < (r_wall_len * 0.85)  && (k < WIDTH * 4))
		{
			translucid = 0;
			//===================================================================//
			if (i > offset_up && i < offset_down)
			{
				if (x < 0)
					x = 0;
				if (x > size - 1)
					x = size - 1;
				y2 = (y * new_size) / wall_len;
				y2 += start_point;
				if (y2 < 0)
					y2 = 0;
				if (y2 > size - 1)
					y2 = size - 1;
				color = tex->tex[(int)y2][(int)x];
				if (color == 0x00FF00FF)
				{
					translucid = 1;
					tmp = j + k;
					if (tmp < 0)
						tmp = 0;
					if (tmp > WIDTH - 1)
						tmp = 0;
					color = get_pixel_img(cub->game, tmp, i);
				}
				int	u;

				u = j + k;
				if (u > WIDTH - 1)
					u = WIDTH - 1;
				if (u < 0)
					u = 0;
				tmp1 = cub->screen[i][u];
				if (!translucid)
				{
					float shadow;
					if (cub->cam_status == OFF)
						shadow = 17;
					else
						shadow = 30;
					shadow = ds / shadow;
					if (shadow >= 1)
						shadow = 1;
					color = ft_mix_color(color, 0x00000000, shadow);
				}
				if (tmp1 > ds)
				{
					ft_put_pixel(cub->game, j + k, i, color);
					if (!translucid)
						cub->screen[i][u] = ds;
				}
			}
			//===================================================================//
			x += chunk;
			k++;
		}
		i++;
	}
	//===================================================================//
	(void)tmp1;
}

//write_map(cub);
void	start_cub(t_cub *cub)
{
	if (cub->cam_status == OFF)
		fill_img_sky_n_ground(cub->game, cub->color_sky, cub->color_ground, 0);
	else
		fill_img_sky_n_ground(cub->game, 0x00FF0000, 0x000000FF, 1);
	ft_fill_img(cub->minimap, 0x00000000);
	ray_caster(cub);
	sprites(cub, 24, 25, cub->nina_t);
	sprites(cub, 24, 27, cub->nina_t);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->game->img, 0, 0);
	if (cub->cam_status == OFF)
	{
		ft_fill_img(cub->atm, \
		ft_mix_color(ft_mix_color(cub->color_sky, \
		cub->color_ground, 0.5), 0xFF000000, 0.60));
		if (cub->cam_animation == 0)
			mlx_put_image_to_window(cub->mlx, cub->win, cub->hand->img, 300 + cub->handx, 200 - cub->handy);
		else
			mlx_put_image_to_window(cub->mlx, cub->win, cub->hand_m->img, 270, 100);
	}
	else
		ft_fill_img(cub->atm, ft_mix_color(0x0000FF00, 0xFF000000, 0.4));

	mlx_put_image_to_window(cub->mlx, cub->win, cub->atm->img, 0, 0);

	if (cub->door == 1)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->hud_o->img, 0, 0);
	else
		mlx_put_image_to_window(cub->mlx, cub->win, cub->hud_c->img, 0, 0);

	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 13, 8);


	put_noise(cub);
	return ;
	(void)cub;
}
