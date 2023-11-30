/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:58:31 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:58:45 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	mouse_release(int key, int x, int y, void *param)
{
	t_cub		*cub;

	cub = (t_cub *)param;
	cub->mouse_press = 0;
	(void)key;
	(void)x;
	(void)y;
}
