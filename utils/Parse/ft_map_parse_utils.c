/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:38:43 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 17:40:06 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

t_height	*ft_new_height_node(char *str)
{
	char		**columns;
	t_height	*map;
	int			i;

	i = 1;
	columns = ft_split(str, ' ');
	if (!columns)
		ft_error_log("SPLIT_COLUMNS");
	map = malloc(sizeof(t_height));
	if (!map)
		ft_error_log("MALLOC_MAP");
	map->next = NULL;
	map->line = ft_new_column_node(columns[0]);
	while (columns[i])
		ft_atach_column(&map->line, ft_new_column_node(columns[i++]));
	ft_free_split(columns);
	return (map);
}

void	ft_atach_line(t_height **list, t_height *node)
{
	t_height	*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

t_height	*ft_init_height(char *doc)
{
	char		**lines;
	t_height	*map;
	int			i;

	i = 1;
	map = NULL;
	lines = ft_split(doc, '\n');
	if (!lines)
		ft_error_log("SPLIT_LINES");
	map = ft_new_height_node(lines[0]);
	while (lines[i])
		ft_atach_line(&map, ft_new_height_node(lines[i++]));
	ft_free_split(lines);
	return (map);
}

void	ft_prove(int i, int j, t_height *tmp1, t_width *tmp2)
{
	while (tmp1)
	{
		tmp2 = tmp1->line;
		j = 0;
		while (tmp2)
		{
			tmp2 = tmp2->next;
			++j;
		}
		if (j != i)
			ft_error_log("INVALID_MAP");
		tmp1 = tmp1->next;
	}
}

void	ft_prove_map(t_height *map)
{
	t_height	*tmp1;
	t_width		*tmp2;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp1 = map;
	if (!tmp1)
		return ;
	tmp2 = tmp1->line;
	while (tmp2)
	{
		tmp2 = tmp2->next;
		i++;
	}
	ft_prove(i, j, tmp1, tmp2);
}
