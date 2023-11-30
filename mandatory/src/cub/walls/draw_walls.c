/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:03:15 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 20:44:55 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

t_dwu	dwu_tmp(size_t total_rays, int side, int win)
{
	t_dwu	result;

	result.total_rays = total_rays;
	result.side = side;
	result.win = win;
	return (result);
}

void	draw_walls(t_cub *cub, t_ray ray, size_t actual_ray, t_dwu du)
{
	t_dw	dw;

	dw.side = du.side;
	dw.win = du.win;
	dw.total_rays = du.total_rays;
	draw_walls_utlis_1(cub, ray, &dw, actual_ray);
	draw_walls_utlis_2(cub, ray, &dw);
	draw_walls_utlis_3(cub, ray, &dw);
	draw_walls_utlis_4(cub, ray, &dw);
	draw_walls_utlis_9(cub, ray, &dw);
	draw_walls_utlis_9(cub, ray, &dw);
}
