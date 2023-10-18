/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:37:05 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/18 10:53:08 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

t_point	ft_proyect(t_point *point, t_fdfc *fdf)
{
	t_point	point_clone;

	ft_make_maths(point, fdf);
	point_clone.x = point->x;
	point_clone.y = point->y;
	point_clone.z = point->z;
	point_clone.color = point->color;
	free(point);
	return (point_clone);
}

void	ft_clone(t_point *point, t_points line, int x, int y)
{
	point->x = x;
	point->y = y;
	point->color = ft_color_degradade(line.start, line.end, *point);
}
