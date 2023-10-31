/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brensenham.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:18:45 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/31 21:30:01 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_get_color(int color, char *str)
{
	if (*str == 'T')
		return ((color >> 24) & 0xFF);
	if (*str == 'R')
		return ((color >> 16) & 0xFF);
	if (*str == 'G')
		return ((color >> 8) & 0xFF);
	if (*str == 'B')
		return ((color) & 0xFF);
	return (0);
}

int	ft_lineal_mix(int c1, int c2, double mix)
{
	return (c1 * (1 - mix) + c2 * mix);
}

int	ft_mix_color(int color1, int color2, double tr)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	t = ft_lineal_mix(ft_get_color(color1, "T"), \
	ft_get_color(color2, "T"), tr);
	r = ft_lineal_mix(ft_get_color(color1, "R"), \
	ft_get_color(color2, "R"), tr);
	g = ft_lineal_mix(ft_get_color(color1, "G"), \
	ft_get_color(color2, "G"), tr);
	b = ft_lineal_mix(ft_get_color(color1, "B"), \
	ft_get_color(color2, "B"), tr);
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_make_translucid(int color1)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 255;
	r = ft_get_color(color1, "R");
	g = ft_get_color(color1, "G");
	b = ft_get_color(color1, "B");
	return (t << 24 | r << 16 | g << 8 | b);
}

double	ft_distance_2_points(t_point a, t_point b)
{
	double	x;
	double	y;

	x = pow((b.x - a.x), 2);
	y = pow((b.y - a.y), 2);
	return (sqrt(x + y));
}

int	ft_color_degradade(t_point init, t_point end, t_point current)
{
	double	total_distance;
	double	actual_distance;
	double	result;

	total_distance = ft_distance_2_points(init, end);
	actual_distance = ft_distance_2_points(init, current);
	result = actual_distance / total_distance;
	return (ft_mix_color(init.color, end.color, result));
}

void	ft_clone(t_point *point, t_points line, int x, int y)
{
	point->x = x;
	point->y = y;
	point->color = ft_color_degradade(line.start, line.end, *point);
}

static void	bb_init(t_bb *bb, t_point f, t_point s)
{
	bb->x0 = f.x;
	bb->y0 = f.y;
	bb->x1 = s.x;
	bb->y1 = s.y;
	bb->dx = ft_abs(bb->x1 - bb->x0);
	bb->dy = ft_abs(bb->y1 - bb->y0);
	if (bb->x0 < bb->x1)
		bb->sx = 1;
	else
		bb->sx = -1;
	if (bb->y0 < bb->y1)
		bb->sy = 1;
	else
		bb->sy = -1;
	bb->err = bb->dx - bb->dy;
	bb->line.start = f;
	bb->line.end = s;
}

void	ft_draw_pixel(t_point point, t_img *img)
{
	ft_put_pixel(img, point.x, point.y, point.color);
}

void	ft_put_line(t_point f, t_point s, t_img *map_display)
{
	t_bb		bb;
	t_point		tmp;
	int			e2;

	bb_init(&bb, f, s);
	while (1)
	{
		ft_clone(&tmp, bb.line, bb.x0, bb.y0);
		ft_draw_pixel(tmp, map_display);
		if (bb.x0 == bb.x1 && bb.y0 == bb.y1)
			break ;
		e2 = 2 * bb.err;
		if (e2 > -bb.dy)
		{
			bb.err -= bb.dy;
			bb.x0 += bb.sx;
		}
		if (e2 < bb.dx)
		{
			bb.err += bb.dx;
			bb.y0 += bb.sy;
		}
	}
}
