/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:51:39 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/18 10:52:41 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx_funtions.h>

void	ft_draw_pixel(t_point point, t_img *img)
{
	ft_put_pixel(img, point.x, point.y, point.color);
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

void	ft_put_line(t_point f, t_point s, t_img *img)
{
	t_bb		bb;
	t_point		tmp;
	int			e2;

	bb_init(&bb, f, s);
	while (1)
	{
		ft_clone(&tmp, bb.line, bb.x0, bb.y0);
		ft_draw_pixel(tmp, img);
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
