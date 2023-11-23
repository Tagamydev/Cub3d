/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:50:41 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/23 19:08:18 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	init_cub(t_cub	*cub)
{
	cub->no_texture = malloc(sizeof(t_img) * 1);
	if (!cub->no_texture)
		return (0);
	cub->no_texture->data_addr = NULL;
	cub->so_texture = malloc(sizeof(t_img) * 1);
	if (!cub->so_texture)
		return (0);
	cub->so_texture->data_addr = NULL;
	cub->ea_texture = malloc(sizeof(t_img) * 1);
	if (!cub->ea_texture)
		return (0);
	cub->ea_texture->data_addr = NULL;
	cub->we_texture = malloc(sizeof(t_img) * 1);
	if (!cub->we_texture)
		return (0);
	cub->we_texture->data_addr = NULL;
	cub->map = NULL;
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