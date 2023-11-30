/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:15:25 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/30 20:16:34 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	free_result_float(float **result, size_t *i)
{
	size_t	j;

	j = 0;
	while (j < *i)
		free(result[j++]);
	free(result);
}

float	**alloc_screen(void)
{
	size_t	i;
	size_t	k;
	float	**result;

	i = 0;
	result = ft_calloc(sizeof(float *), HEIGHT);
	if (!result)
		return (NULL);
	while (i < HEIGHT)
	{
		k = 0;
		result[i] = ft_calloc(sizeof(float), WIDTH);
		if (!result[i])
		{
			free_result_float(result, &i);
			return (NULL);
		}
		while (k < WIDTH)
			result[i][k++] = 30;
		i++;
	}
	return (result);
}

void	map_parsing_aux(t_cub *cub)
{
	if (cub->player_a == 2)
		cub->player_a = 270;
	else if (cub->player_a == 3)
		cub->player_a = 90;
	else if (cub->player_a == 4)
		cub->player_a = 180;
	else if (cub->player_a == 5)
		cub->player_a = 0;
	cub->player_a += 0.1;
	cub->minimap_zoom = ZOOM_L;
	cub->cam_status = OFF;
	cub->camera_speed = 2;
	cub->player_px += 0.5;
	cub->player_py += 0.5;
	put_deltas(cub);
	cub->door = 0;
	cub->fisheye = 0;
	cub->handx = 0;
	cub->handy = 0;
	cub->frame = 0;
	cub->cam_animation = 0;
	cub->screen = alloc_screen();
}
