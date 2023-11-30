/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:20:28 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 14:05:13 by samusanc         ###   ########.fr       */
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

#endif

