/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:19:10 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 20:19:28 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	draw_walls_utlis_8(t_cub *cub, t_ray ray, t_dw *dw)
{
	if (cub->cam_status == ON)
	{
		ray.color = 0x0011f752;
		if (dw->side == 0xcc || dw->side == 0xcc00)
			ray.color = ft_mix_color(ray.color, 0x00000000, 0.5);
		ray.color = ft_mix_color(ray.color, 0x00000000, ray.shadow);
		if (dw->fog == 1)
			ray.color = 0;
		ft_put_pixel(cub->game, dw->j, dw->i, ray.color);
	}
	cub->screen[dw->i][dw->j] = ray.distance;
	dw->wall_len += 1;
	(void)cub;
	(void)ray;
}

void	draw_walls_utlis_7(t_cub *cub, t_ray ray, t_dw *dw)
{
	if (dw->i > dw->offset_up && dw->i < dw->offset_down)
		draw_walls_utlis_8(cub, ray, dw);
	else
		cub->screen[dw->i][dw->j] = 30;
	(void)cub;
	(void)ray;
}

void	draw_walls_utlis_6(t_cub *cub, t_ray ray, t_dw *dw)
{
	while (dw->k != dw->len)
	{
		draw_walls_utlis_7(cub, ray, dw);
		dw->k++;
		dw->j++;
	}
	(void)cub;
	(void)ray;
}

void	draw_walls_utlis_5_init(t_cub *cub, t_ray ray, t_dw *dw)
{
	dw->j = dw->start_x;
	dw->k = 0;
	(void)cub;
	(void)ray;
}

void	draw_walls_utlis_4(t_cub *cub, t_ray ray, t_dw *dw)
{
	while (dw->i < HEIGHT)
	{
		draw_walls_utlis_5_init(cub, ray, dw);
		draw_walls_utlis_6(cub, ray, dw);
		dw->i++;
	}
	(void)cub;
	(void)ray;
}
