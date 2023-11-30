/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:37:49 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 20:52:18 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
# define BRESENHAM_H
# include <math.h>

typedef struct s_point{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_points{
	t_point	start;
	t_point	end;
}				t_points;

typedef struct s_bb{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
	t_points	line;
}				t_bb;

struct	s_img;

void	ft_put_pixel(struct s_img *img, int x, int y, int color);
int		ft_abs(int x);
int		ft_get_color(int color, char *str);
int		ft_lineal_mix(int c1, int c2, double mix);
int		ft_mix_color(int color1, int color2, double tr);
int		ft_make_translucid(int color1);
double	ft_distance_2_points(t_point a, t_point b);
int		ft_color_degradade(t_point init, t_point end, t_point current);
void	ft_clone(t_point *point, t_points line, int x, int y);
void	ft_draw_pixel(t_point point, struct s_img *img);
void	ft_put_line(t_point f, t_point s, struct s_img *map_display);

#endif
