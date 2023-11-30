/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:30:56 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/25 19:26:41 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	separate_aux(t_cub *cub, char **archive, int *count_line)
{
	int	ret;

	*count_line = 0;
	while (archive[*count_line])
	{
		ret = fill_struct(cub, archive[*count_line]);
		if (!ret)
			return (0);
		if (ret == 2)
			break ;
		*count_line += 1;
	}
	return (1);
}

void	separate_aux2(t_cub *cub, char **archive, int *count_line)
{
	int	count;

	count = 0;
	while (archive[*count_line + count])
	{
		if (archive[*count_line + count][0] == '\n')
			break ;
		count++;
	}
	cub->map_height = count;
}

int	separate_aux3(char **archive, int *count_line, int *count)
{
	int	i;

	i = 0;
	if (archive[*count_line + *count][i] == ' ')
	{
		while (archive[*count_line + *count][i] == ' ')
			i++;
		if (!archive[*count_line + *count][i]
			|| archive[*count_line + *count][i] == '\n')
			return (0);
		*count += 1;
	}
	if (archive[*count_line + *count][0] == '\n')
	{
		while (archive[*count_line + *count])
		{
			if (archive[*count_line + *count][0] != '\n')
				return (0);
			*count += 1;
		}
	}
	else
		*count += 1;
	return (1);
}

int	separate(t_cub *cub, char **archive)
{
	int	count_line;
	int	count;

	count = 0;
	if (!separate_aux(cub, archive, &count_line))
		return (0);
	while (archive[count_line + count])
	{
		if (!separate_aux3(archive, &count_line, &count))
			return (0);
	}
	separate_aux2(cub, archive, &count_line);
	if (!copy_map(cub, &archive[count_line]))
		return (0);
	if (!check_maps(cub))
		return (0);
	return (1);
}
