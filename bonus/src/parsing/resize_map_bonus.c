/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:08:48 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/30 23:13:03 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	free_result(size_t **result, size_t *i)
{
	size_t	j;

	j = 0;
	while (j < *i)
		free(result[j++]);
	free(result);
}

size_t	**alloc_new_map(size_t size)
{
	size_t	i;
	size_t	k;
	size_t	**result;

	i = 0;
	result = ft_calloc(sizeof(size_t *), size);
	if (!result)
		return (NULL);
	while (i < size)
	{
		k = 0;
		result[i] = ft_calloc(sizeof(size_t), size);
		if (!result[i])
		{
			free_result(result, &i);
			return (NULL);
		}
		while (k < size)
			result[i][k++] = 1;
		i++;
	}
	return (result);
}

int	resize_map_aux(t_cub *cub, size_t *tmp, size_t *i, size_t **new_map)
{
	size_t	j;

	j = 0;
	while (j < cub->map_width)
	{
		*tmp = cub->map[*i][j];
		if (*tmp == 9)
			*tmp = 1;
		new_map[*i + 20][j + 20] = *tmp;
		j++;
	}
	free(cub->map[*i]);
	*i += 1;
	return (1);
}

int	resize_map(t_cub *cub)
{
	size_t	x;
	size_t	**new_map;
	size_t	i;
	size_t	tmp;

	if (cub->map_width > cub->map_height)
		x = cub->map_width;
	else
		x = cub->map_height;
	new_map = alloc_new_map(x + 40);
	if (!new_map)
		return (0);
	i = 0;
	while (i < cub->map_height)
	{
		if (!resize_map_aux(cub, &tmp, &i, new_map))
			return (0);
	}
	free(cub->map);
	cub->map = new_map;
	cub->map_width = x + 40;
	cub->map_height = x + 40;
	cub->player_px += 20;
	cub->player_py += 20;
	return (1);
}
