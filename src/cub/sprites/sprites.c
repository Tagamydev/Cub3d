/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:10:05 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:10:17 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	sprites(t_cub *cub, float sx, float sy, t_tex *tex)
{
	float	x;
	float	y;
	float	angle;
	float	angle2;
	float	up;
	float	down;
	float	screenx;
	float	ds;
	float	distance;
	float	offset_up;
	float	offset_down;
	float	offset_left;
	float	offset_right;
	float	offup;
	float	offdo;
	float	offset;
	float	chunk;
	float	offl;
	float	offr;
	float	txt_i;
	float	txt_f;
	float	y2;
	float	new_size;
	float	start_point;
	float	end_point;
	float	real_wall_ds;
	float	z;
	float	chunk2;
	float	shadow;
	int		side;
	int		i;
	int		j;
	int		r_wall_len;
	int		k;
	int		initial;
	int		final;
	int		size;
	int		color;
	int		tmp;
	int		u;
	float	tmp1;
	size_t	wall_len;

	//=========================================================//
	if (!tex)
		return ;
	sx += 0.5;
	sy += 0.5;
	if (cub->player_py - sy < 0)
		side = -1;
	else
		side = 1;
	ds = ft_ds(sx, cub->player_px, sy, cub->player_py);
	if (ds > 35)
		return ;
	up = sx - cub->player_px;
	down = ds;
	angle = acos(up / down) * 180.0 / PI;
	angle *= side;
	if (cub->player_a > 180)
		angle2 = cub->player_a - 360;
	else
		angle2 = cub->player_a;
	angle = angle2 + angle;
	angle *= -1;
	angle += 15;
	screenx = (angle * WIDTH) / (float)30;
	//===================================================================//
	wall_len = 0;
	distance = (240 * 15) / ds;
	distance = distance / 5;
	offset_up = ((HEIGHT / 2.5) - distance);
	offset_down = (HEIGHT / 1.25 - offset_up);
	i = 0;
	while (i < HEIGHT)
	{
		j = screenx;
		if (i > offset_up && i < offset_down)
			wall_len += 1;
		i++;
	}
	//===================================================================//
	offset_left = 0;
	offset_right = 0;
	if (screenx < 0)
		offset_left = screenx * (-1);
	if (screenx > WIDTH)
		offset_right = screenx - WIDTH;
	r_wall_len = ft_abs(offset_up - offset_down);
	if (offset_left > r_wall_len || offset_right > wall_len)
		return ;
	//===================================================================//
	i = 0;
	size = tex->size;
	if (offset_up < 0)
		offup = (float)ft_abs(offset_up) / (float)HEIGHT;
	else
		offup = 0;
	if (offset_down > HEIGHT)
		offdo = (float)ft_abs(offset_down - HEIGHT) / (float)HEIGHT;
	else
		offdo = 0;
	offset = (offup) * ((float)r_wall_len);
	initial = screenx - ((float)(r_wall_len) / (float)2.35);
	chunk = (r_wall_len * 0.85);
	final = initial + chunk;
	//===================================================================//
	y = 0;
	start_point = 0;
	end_point = size;
	start_point = 0;
	end_point = size;
	real_wall_ds = ft_abs(offset_up - offset_down);
	if (offset_up < 0)
	{
		start_point = (float)(ft_abs(offset_up) * size) / (float)real_wall_ds;
		if (offset_down > HEIGHT)
			end_point = size - ((float)(ft_abs(offset_down - HEIGHT) * size) / (float)real_wall_ds);
	}
	new_size = ft_abs2(start_point - end_point);
	//===================================================================//
	if (initial < 0)
		offl = ft_abs(initial);
	else
		offl = 0;
	if (final > 640)
		offr = final - WIDTH;
	else
		offr = 0;
	txt_i = (float)(ft_abs(offl) * new_size) / chunk;
	if (txt_i < 0)
		txt_i = 0;
	if (txt_i > size - 1)
		txt_i = size - 1;
	txt_f = size - (float)(ft_abs(offr) * new_size) / chunk;
	if (txt_f < 0)
		txt_f = 0;
	if (txt_f > size - 1)
		txt_f = size - 1;
	z = 0;
	x = 0;
	y = 0;
	chunk = (float)(ft_abs2(txt_i - txt_f)) / (float)(r_wall_len * 0.85);
	chunk2 = 1;
	int	translucid;
	//===================================================================//
	while (i < HEIGHT)
	{
		x = txt_i;
		j = initial;
		k = 0;
		if (i > offset_up && i < offset_down)
			y++;
		while (k < (r_wall_len * 0.85)  && (k < WIDTH * 4))
		{
			translucid = 0;
			//===================================================================//
			if (i > offset_up && i < offset_down)
			{
				if (x < 0)
					x = 0;
				if (x > size - 1)
					x = size - 1;
				y2 = (y * new_size) / wall_len;
				y2 += start_point;
				if (y2 < 0)
					y2 = 0;
				if (y2 > size - 1)
					y2 = size - 1;
				color = tex->tex[(int)y2][(int)x];
				if (color == 0x00FF00FF)
				{
					translucid = 1;
					tmp = j + k;
					if (tmp < 0)
						tmp = 0;
					if (tmp > WIDTH - 1)
						tmp = 0;
					color = get_pixel_img(cub->game, tmp, i);
				}
				u = j + k;
				if (u > WIDTH - 1)
					u = WIDTH - 1;
				if (u < 0)
					u = 0;
				tmp1 = cub->screen[i][u];
				if (!translucid)
				{
					if (cub->cam_status == OFF)
						shadow = 17;
					else
						shadow = 30;
					shadow = ds / shadow;
					if (shadow >= 1)
						shadow = 1;
					color = ft_mix_color(color, 0x00000000, shadow);
				}
				if (tmp1 > ds)
				{
					ft_put_pixel(cub->game, j + k, i, color);
					if (!translucid)
						cub->screen[i][u] = ds;
				}
			}
			//===================================================================//
			x += chunk;
			k++;
		}
		i++;
	}
	//===================================================================//
	(void)tmp1;
}
