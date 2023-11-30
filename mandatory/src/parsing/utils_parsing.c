/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:50:41 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/25 18:41:31 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	init_cub(t_cub	*cub)
{
	cub->no_texture = NULL;
	cub->so_texture = NULL;
	cub->ea_texture = NULL;
	cub->we_texture = NULL;
	cub->map = NULL;
	cub->mlx = mlx_init();
	cub->color_ground = -1;
	cub->color_sky = -1;
	cub->map_width = 0;
	cub->map_height = 0;
	return (1);
}

void	free_archive(char **archive)
{
	int	row;

	row = 0;
	while (archive[row])
	{
		free(archive[row]);
		row++;
	}
	free(archive);
}

size_t	ft_strlcpys(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
