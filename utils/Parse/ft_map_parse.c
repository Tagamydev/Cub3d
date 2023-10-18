/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:16:30 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 17:40:13 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

t_height	*ft_make_map(char *str)
{
	int			fd;
	char		*doc;
	t_height	*map;

	map = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error_log("FD_OPEN");
	doc = get_all_doc(fd);
	if (!doc)
		ft_error_log("GNL");
	map = ft_init_height(doc);
	fd = close(fd);
	if (fd == -1)
		ft_error_log("FD_CLOSE");
	ft_free_string(&doc);
	ft_prove_map(map);
	return (map);
}

int	ft_get_lenght(char *str, t_height *map)
{
	t_height	*tmp1;
	t_width		*tmp2;
	int			i;

	i = 0;
	tmp1 = map;
	tmp2 = map->line;
	if (*str == 'H')
	{
		while (tmp1)
		{
			tmp1 = tmp1->next;
			i++;
		}
	}
	else
	{
		while (tmp2)
		{
			tmp2 = tmp2->next;
			i++;
		}
	}
	return (i);
}

t_width	*ft_new_column_node(char *str)
{
	char	**numbers;
	t_width	*col;

	numbers = ft_split(str, ',');
	if (!numbers)
		ft_error_log("SPLIT_NUMBERS");
	col = malloc(sizeof(t_width));
	if (!col)
		ft_error_log("MALLOC_MAP");
	col->z = ft_atoi_base(numbers[0], 10);
	if (numbers[1])
		col->color = ft_atoi_base(numbers[1], 16);
	else
		col->color = 0x00FFFFFF;
	col->next = NULL;
	ft_free_split(numbers);
	return (col);
}

void	ft_atach_column(t_width **list, t_width *node)
{
	t_width	*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}
