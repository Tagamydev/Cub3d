/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:37:05 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/19 10:51:13 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

static void	ft_proyect_minimap_util(t_cub *cub, int *max, double *i)
{
	if (cub->map->width > cub->map->height)
		*max = cub->map->width;
	else
		*max = cub->map->height;
	if (*max > 200)
	{
		*i = 1;
		while (*max)
		{
			*i = *i / 1.2;
			*max = *max / 10;
		}
	}
	else
		*i = 200 / *max;
}

t_point	ft_proyect_minimap(t_point *point, t_cub *cub)
{
	t_point	point_clone;
	int		max;
	double	i;

	max = 0;
	i = 0;
	ft_proyect_minimap_util(cub, &max, &i);
	point_clone.x = point->x * i;
	point_clone.y = point->y * i;
	point_clone.z = point->z * i;
	point_clone.color = point->color;
	free(point);
	cub = NULL;
	return (point_clone);
}

t_point	ft_proyect(t_point *point, t_cub *cub)
{
	t_point	point_clone;

	ft_make_maths(point, cub);
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
