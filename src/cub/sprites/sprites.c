/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:10:05 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 18:02:18 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	sprites(t_cub *cub, float sx, float sy, t_tex *tex)
{
	t_sp	sp;

	//=========================================================//
	if (!tex)
		return ;
	sx += 0.5;
	sy += 0.5;
	if (cub->player_py - sy < 0)
		sp.side = -1;
	else
		sp.side = 1;
	sp.ds = ft_ds(sx, cub->player_px, sy, cub->player_py);
	if (sp.ds > 35)
		return ;
	sp.up = sx - cub->player_px;
	sp.down = sp.ds;
	sp.angle = acos(sp.up / sp.down) * 180.0 / PI;
	sp.angle *= sp.side;
	if (cub->player_a > 180)
		sp.angle2 = cub->player_a - 360;
	else
		sp.angle2 = cub->player_a;
	sp.angle = sp.angle2 + sp.angle;
	sp.angle *= -1;
	sp.angle += 15;
	sp.screenx = (sp.angle * WIDTH) / (float)30;
	//===================================================================//
	sp.wall_len = 0;
	sp.distance = (240 * 15) / sp.ds;
	sp.distance = sp.distance / 5;
	sp.offset_up = ((HEIGHT / 2.5) - sp.distance);
	sp.offset_down = (HEIGHT / 1.25 - sp.offset_up);
	sp.i = 0;
	while (sp.i < HEIGHT)
	{
		sp.j = sp.screenx;
		if (sp.i > sp.offset_up && sp.i < sp.offset_down)
			sp.wall_len += 1;
		sp.i++;
	}
	//===================================================================//
	sp.offset_left = 0;
	sp.offset_right = 0;
	if (sp.screenx < 0)
		sp.offset_left = sp.screenx * (-1);
	if (sp.screenx > WIDTH)
		sp.offset_right = sp.screenx - WIDTH;
	sp.r_wall_len = ft_abs(sp.offset_up - sp.offset_down);
	if (sp.offset_left > sp.r_wall_len || sp.offset_right > sp.wall_len)
		return ;
	//===================================================================//
	sp.i = 0;
	sp.size = tex->size;
	if (sp.offset_up < 0)
		sp.offup = (float)ft_abs(sp.offset_up) / (float)HEIGHT;
	else
		sp.offup = 0;
	if (sp.offset_down > HEIGHT)
		sp.offdo = (float)ft_abs(sp.offset_down - HEIGHT) / (float)HEIGHT;
	else
		sp.offdo = 0;
	sp.offset = (sp.offup) * ((float)sp.r_wall_len);
	sp.initial = sp.screenx - ((float)(sp.r_wall_len) / (float)2.35);
	sp.chunk = (sp.r_wall_len * 0.85);
	sp.final = sp.initial + sp.chunk;
	//===================================================================//
	sp.y = 0;
	sp.start_point = 0;
	sp.end_point = sp.size;
	sp.start_point = 0;
	sp.end_point = sp.size;
	sp.real_wall_ds = ft_abs(sp.offset_up - sp.offset_down);
	if (sp.offset_up < 0)
	{
		sp.start_point = (float)(ft_abs(sp.offset_up) * sp.size) / (float)sp.real_wall_ds;
		if (sp.offset_down > HEIGHT)
			sp.end_point = sp.size - ((float)(ft_abs(sp.offset_down - HEIGHT) * sp.size) / (float)sp.real_wall_ds);
	}
	sp.new_size = ft_abs2(sp.start_point - sp.end_point);
	//===================================================================//
	if (sp.initial < 0)
		sp.offl = ft_abs(sp.initial);
	else
		sp.offl = 0;
	if (sp.final > 640)
		sp.offr = sp.final - WIDTH;
	else
		sp.offr = 0;
	sp.txt_i = (float)(ft_abs(sp.offl) * sp.new_size) / sp.chunk;
	if (sp.txt_i < 0)
		sp.txt_i = 0;
	if (sp.txt_i > sp.size - 1)
		sp.txt_i = sp.size - 1;
	sp.txt_f = sp.size - (float)(ft_abs(sp.offr) * sp.new_size) / sp.chunk;
	if (sp.txt_f < 0)
		sp.txt_f = 0;
	if (sp.txt_f > sp.size - 1)
		sp.txt_f = sp.size - 1;
	sp.z = 0;
	sp.x = 0;
	sp.y = 0;
	sp.chunk = (float)(ft_abs2(sp.txt_i - sp.txt_f)) / (float)(sp.r_wall_len * 0.85);
	sp.chunk2 = 1;
	//===================================================================//
	while (sp.i < HEIGHT)
	{
		sp.x = sp.txt_i;
		sp.j = sp.initial;
		sp.k = 0;
		if (sp.i > sp.offset_up && sp.i < sp.offset_down)
			sp.y++;
		if (sp.i % 3 == 0)
			sp.zx = 0;
		else
			sp.zx = 1;
		if (cub->cam_status == OFF)
			sp.zx = 1;
		while (sp.k < (sp.r_wall_len * 0.85)  && (sp.k < WIDTH * 4))
		{
			if (sp.k % 3 == 0)
				sp.zz = 0;
			else
				sp.zz = 1;
			if (cub->cam_status == OFF)
				sp.zz = 1;
			sp.translucid = 0;
			//===================================================================//
			if (sp.i > sp.offset_up && sp.i < sp.offset_down && (sp.zz && sp.zx))
			{
				if (sp.x < 0)
					sp.x = 0;
				if (sp.x > sp.size - 1)
					sp.x = sp.size - 1;
				sp.y2 = (sp.y * sp.new_size) / sp.wall_len;
				sp.y2 += sp.start_point;
				if (sp.y2 < 0)
					sp.y2 = 0;
				if (sp.y2 > sp.size - 1)
					sp.y2 = sp.size - 1;
				sp.color = tex->tex[(int)sp.y2][(int)sp.x];
				if (sp.color == 0x00FF00FF)
				{
					sp.translucid = 1;
					sp.tmp = sp.j + sp.k;
					if (sp.tmp < 0)
						sp.tmp = 0;
					if (sp.tmp > WIDTH - 1)
						sp.tmp = 0;
					sp.color = get_pixel_img(cub->game, sp.tmp, sp.i);
				}
				sp.u = sp.j + sp.k;
				if (sp.u > WIDTH - 1)
					sp.u = WIDTH - 1;
				if (sp.u < 0)
					sp.u = 0;
				sp.tmp1 = cub->screen[sp.i][sp.u];
				if (!sp.translucid)
				{
					if (cub->cam_status == OFF)
						sp.shadow = 17;
					else
						sp.shadow = 30;
					sp.shadow = sp.ds / sp.shadow;
					if (sp.shadow >= 1)
						sp.shadow = 1;
					sp.color = ft_mix_color(sp.color, 0x00000000, sp.shadow);
				}
				if (sp.tmp1 > sp.ds)
				{
					ft_put_pixel(cub->game, sp.j + sp.k, sp.i, sp.color);
					if (!sp.translucid)
						cub->screen[sp.i][sp.u] = sp.ds;
				}
			}
			//===================================================================//
			sp.x += sp.chunk;
			sp.k++;
		}
		sp.i++;
	}
	//===================================================================//
	(void)sp.tmp1;
}
