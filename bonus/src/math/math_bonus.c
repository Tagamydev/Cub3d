/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:11:50 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 13:28:03 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>

t_p	intersection_btw_lines(t_line line1, t_line line2)
{
	t_p	result;

	result.x = (line2.b - line1.b) / (line1.m - line2.m);
	result.y = (line1.m * result.x) + line1.b;
	result.dx = 0;
	result.dy = 0;
	return (result);
}

t_p	intersection_btw_points(t_p p1, t_p p2)
{
	t_p		p11;
	t_p		p21;
	t_line	line1;
	t_line	line2;

	p11.x = p1.x + p1.dx * 10;
	p11.y = p1.y + p1.dy * 10;
	p21.x = p2.x + p2.dx * 10;
	p21.y = p2.y + p2.dy * 10;
	line1 = make_line_with_two_points(p1, p11);
	line2 = make_line_with_two_points(p2, p21);
	return (intersection_btw_lines(line1, line2));
}
