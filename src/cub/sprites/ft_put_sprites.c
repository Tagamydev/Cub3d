/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:10:57 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:11:09 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	ft_put_sprites(t_cub *cub)
{
	t_tex	*tex;
	t_spr	*tmp;
	size_t	i;

	i = 0;
	while (cub->sprites[i])
	{
		tmp = (cub->sprites[i]);
		tex = get_tex(cub, tmp); 
		sprites(cub, tmp->x, tmp->y, tex);
		i++;
	}
	tex = NULL;
	(void)cub;
}
