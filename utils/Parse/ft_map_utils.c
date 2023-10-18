/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:17:47 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 17:41:03 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	ft_print_line_map(t_width *line, int y)
{
	t_width	*tmp;
	int		x;

	x = 0;
	tmp = line;
	while (tmp)
	{
		ft_printf("(%d, %d) = number:%d, color:%p\n", \
		x++, y, tmp->z, tmp->color);
		tmp = tmp->next;
	}
}

void	ft_print_mapi(t_height *map)
{
	t_height	*tmp;
	int			y;

	y = 0;
	tmp = map;
	while (map)
	{
		ft_print_line_map(map->line, y++);
		map = map->next;
	}
}

void	ft_free_line_map(t_width *map)
{
	t_width	*tmp;
	t_width	*tmp2;

	if (!map)
		return ;
	tmp = map;
	tmp2 = tmp->next;
	while (tmp2)
	{
		free(tmp);
		tmp = tmp2;
		tmp2 = tmp->next;
	}
	free(tmp);
}

void	ft_free_map(t_height *map)
{
	t_height	*tmp;
	t_height	*tmp2;

	if (!map)
		return ;
	tmp = map;
	tmp2 = tmp->next;
	while (tmp2)
	{
		ft_free_line_map(tmp->line);
		free(tmp);
		tmp = tmp2;
		tmp2 = tmp->next;
	}
	ft_free_line_map(tmp->line);
	free(tmp);
}
