/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:13:14 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/30 20:16:32 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

t_spr	*new_sprite(size_t x, size_t y, int frame)
{
	t_spr	*new;

	new = malloc(sizeof(t_spr));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->next_frame = 0;
	new->next_blink = 0;
	new->blink = 0;
	if (frame > 4)
		frame = 4;
	new->frame = frame;
	return (new);
}

int	put_sprites_aux(t_cub *cub, size_t *tmp)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	x = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width)
		{
			*tmp = cub->map[i][j];
			if (*tmp == 10)
			{
				cub->sprites[x] = new_sprite(j, i, ft_random(1, 0, 4));
				if (!cub->sprites[x++])
					return (0);
				cub->map[i][j] = 0;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	count_tam_spr(t_cub *cub, size_t *tmp, size_t *k)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width)
		{
			*tmp = cub->map[i][j];
			if (!BONUS)
			{
				if (*tmp == 10)
					return (0);
			}
			if (*tmp == 10)
				*k += 1;
			j++;
		}
		i++;
	}
	return (1);
}

int	put_sprites(t_cub *cub)
{
	size_t	k;
	size_t	tmp;

	k = 0;
	if (!count_tam_spr(cub, &tmp, &k))
		return (0);
	cub->sprites = malloc(sizeof(t_spr *) * (k + 1));
	if (!cub->sprites)
		return (0);
	cub->sprites[k] = NULL;
	if (!put_sprites_aux(cub, &tmp))
		return (0);
	return (1);
}
