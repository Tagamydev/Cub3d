/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_dpi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:55:26 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:55:42 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	increase_dpi(t_cub *cub, int key)
{
	if (key == 18)
		cub->camera_speed = 2;
	else if (key == 19)
		cub->camera_speed = 5;
	else
		cub->camera_speed = 25;
}
