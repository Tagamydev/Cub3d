/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:03:22 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 17:43:00 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

int	ft_get_col(t_height *map, int x, int y)
{
	t_height	*tmp1;
	t_width		*tmp2;
	int			i;
	int			j;

	i = 0;
	tmp1 = map;
	tmp2 = tmp1->line;
	while (tmp1)
	{
		if (i++ == y)
		{
			j = 0;
			tmp2 = tmp1->line;
			while (tmp2)
			{
				if (j++ == x)
					break ;
				tmp2 = tmp2->next;
			}
			break ;
		}
		tmp1 = tmp1->next;
	}
	return (tmp2->color);
}

int	ft_get_z(t_height *map, int x, int y)
{
	t_height	*tmp1;
	t_width		*tmp2;
	int			i;
	int			j;

	i = 0;
	tmp1 = map;
	tmp2 = tmp1->line;
	while (tmp1)
	{
		if (i++ == y)
		{
			j = 0;
			tmp2 = tmp1->line;
			while (tmp2)
			{
				if (j++ == x)
					break ;
				tmp2 = tmp2->next;
			}
			break ;
		}
		tmp1 = tmp1->next;
	}
	return (tmp2->z);
}

t_point	*ft_get_point(t_height *map, int x, int y)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		ft_error_log("MALLOC_POINT");
	point->z = ft_get_z(map, x, y);
	point->color = ft_get_col(map, x, y);
	point->x = x;
	point->y = y;
	return (point);
}
