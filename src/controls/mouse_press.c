/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:58:07 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:58:16 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	mouse_press(int key, int x, int y, void *param)
{
	t_cub		*cub;

	cub = (t_cub *)param;
	if ((x >= 529 && x <= 589) && (y >= 396 && y <= 456))
	{
		if (cub->door == 0)
			open_doors(cub);
		else
			close_doors(cub);
	}
	cub->mouse_press = 1;
	(void)key;
}
