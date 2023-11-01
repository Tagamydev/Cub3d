/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:20:28 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/01 02:28:00 by samusanc         ###   ########.fr       */
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

typedef struct s_ray{
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	x_offset;
	float	y_offset;
	float	atan;
}				t_ray;

#endif

