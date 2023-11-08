/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:59:53 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/08 14:04:34 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <stdio.h>
# include <math.h>
# ifndef PI
#  define PI 3.1415926535
# endif

typedef struct s_p{
	float	x;
	float	y;
	float	dx;
	float	dy;
}		t_p;

typedef	struct s_line{
	t_p	p1;
	t_p	p2;
	float	m;
	float	b;
}		t_line;


t_p	make_point_no_dir(float x, float y);
t_p	make_point_with_dir(float x, float y, float dx, float dy);
t_line	make_line_with_two_points(t_p p1, t_p p2);
t_line	make_line_with_one_point(t_p p);
t_p	intersection_btw_lines(t_line line1, t_line line2);
t_p	intersection_btw_points(t_p p1, t_p p2);

#endif
