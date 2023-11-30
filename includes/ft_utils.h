/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:20:28 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 17:35:33 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdio.h>

typedef struct s_put_walls{
	int	i;
	int	j;
	int	minx;
	int	x2;
	int	y2;
}				t_put_walls;

typedef struct s_square{
	int	x;
	int	y;
	int len;
	int color;
}				t_square;

typedef struct s_sg{
	int		i;
	int		j;
	float	m;
	int		color;
	int		color1;
	int		color2;
	float	x;
	int		cam;
	int		ground;
}				t_sg;

typedef struct s_rayc{
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
}				t_rayc;

typedef struct s_stat{
	double	x;
	double	y;
	double	ray_dx;
	double	ray_dy;
	float	ray_proyection;
	int		status1;
}				t_stat;

typedef struct s_stat1{
	float	last_distance;
	float	ray_a;
	float	*ds;
	int		m;
}				t_stat1;

typedef struct s_sp{
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
	float	shadow;
	float	tmp1;
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
	int		u;
	int		zz;
	int		zx;
	int		translucid;
	size_t	wall_len;
}				t_sp;

#endif

