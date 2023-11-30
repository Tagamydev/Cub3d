/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:26:54 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 13:28:22 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>

t_line	make_line_with_two_points(t_p p1, t_p p2)
{
	t_line	line;

	line.p1 = p1;
	line.p2 = p2;
	line.m = (p2.y - p1.y) / (p2.x - p1.x);
	line.b = p1.y - (line.m * p1.x);
	return (line);
}

t_line	make_line_with_one_point(t_p p1)
{
	t_p	p2;

	p2 = p1;
	p2.x = p1.x + p1.dx * 5;
	p2.y = p1.y + p1.dy * 5;
	return (make_line_with_two_points(p1, p2));
}

t_p	make_point_with_dir(float x, float y, float dx, float dy)
{
	t_p	point;

	point.x = x;
	point.y = y;
	point.dy = dy;
	point.dx = dx;
	return (point);
}

t_p	make_point_no_dir(float x, float y)
{
	t_p	point;

	point.x = x;
	point.y = y;
	point.dy = 0;
	point.dx = 0;
	return (point);
}
