/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:10:05 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 19:01:05 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static void	sprites_utils_3(t_cub *cub, t_sp *sp)
{
	sp->offset_left = 0;
	sp->offset_right = 0;
	if (sp->screenx < 0)
		sp->offset_left = sp->screenx * (-1);
	if (sp->screenx > WIDTH)
		sp->offset_right = sp->screenx - WIDTH;
	sp->r_wall_len = ft_abs(sp->offset_up - sp->offset_down);
	if (sp->offset_left > sp->r_wall_len || sp->offset_right > sp->wall_len)
		return ;
	(void)cub;
}

static void	sprites_utils_2(t_cub *cub, t_sp *sp)
{
	sp->wall_len = 0;
	sp->distance = (240 * 15) / sp->ds;
	sp->distance = sp->distance / 5;
	sp->offset_up = ((HEIGHT / 2.5) - sp->distance);
	sp->offset_down = (HEIGHT / 1.25 - sp->offset_up);
	sp->i = 0;
	while (sp->i < HEIGHT)
	{
		sp->j = sp->screenx;
		if (sp->i > sp->offset_up && sp->i < sp->offset_down)
			sp->wall_len += 1;
		sp->i++;
	}
	(void)cub;
}

static void	sprites_utils_1(t_cub *cub, t_sp *sp, float sx, float sy)
{
	sx += 0.5;
	sy += 0.5;
	if (cub->player_py - sy < 0)
		sp->side = -1;
	else
		sp->side = 1;
	sp->ds = ft_ds(sx, cub->player_px, sy, cub->player_py);
	if (sp->ds > 35)
		return ;
	sp->up = sx - cub->player_px;
	sp->down = sp->ds;
	sp->angle = acos(sp->up / sp->down) * 180.0 / PI;
	sp->angle *= sp->side;
	if (cub->player_a > 180)
		sp->angle2 = cub->player_a - 360;
	else
		sp->angle2 = cub->player_a;
	sp->angle = sp->angle2 + sp->angle;
	sp->angle *= -1;
	sp->angle += 15;
	sp->screenx = (sp->angle * WIDTH) / (float)30;
	(void)cub;
}

void	sprites(t_cub *cub, float sx, float sy, t_tex *tex)
{
	t_sp	sp;

	if (!tex)
		return ;
	sprites_utils_1(cub, &sp, sx, sy);
	sprites_utils_2(cub, &sp);
	sprites_utils_3(cub, &sp);
	sprites_utils_4(cub, &sp, tex);
	sprites_utils_5(cub, &sp);
	sprites_utils_6(cub, &sp);
	sprites_utils_7(cub, &sp);
	sprites_utils_8(cub, &sp, tex);
}
