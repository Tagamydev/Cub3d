/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster_funtions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:09:32 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:09:44 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	ray_caster(t_cub *cub)
{
	draw_minimap(cub);
	draw_direction(cub);
	draw_minimark(cub);
	draw_ray_map(cub);
	draw_cross(cub);
}
