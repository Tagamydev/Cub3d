/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:57:01 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 19:01:49 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	sprites_utils_8(t_cub *cub, t_sp *sp, t_tex *tex)
{
	while (sp->i < HEIGHT)
	{
		sprites_utils_9(cub, sp, tex);
		sprites_utils_10(cub, sp, tex);
		sp->i++;
	}
	(void)cub;
}

void	sprites_utils_7(t_cub *cub, t_sp *sp)
{
	sp->z = 0;
	sp->x = 0;
	sp->y = 0;
	sp->chunk = (float)(ft_abs2(sp->txt_i - sp->txt_f)) \
	/ (float)(sp->r_wall_len * 0.85);
	sp->chunk2 = 1;
	(void)cub;
}

void	sprites_utils_6(t_cub *cub, t_sp *sp)
{
	if (sp->initial < 0)
		sp->offl = ft_abs(sp->initial);
	else
		sp->offl = 0;
	if (sp->final > 640)
		sp->offr = sp->final - WIDTH;
	else
		sp->offr = 0;
	sp->txt_i = (float)(ft_abs(sp->offl) * sp->new_size) / sp->chunk;
	if (sp->txt_i < 0)
		sp->txt_i = 0;
	if (sp->txt_i > sp->size - 1)
		sp->txt_i = sp->size - 1;
	sp->txt_f = sp->size - (float)(ft_abs(sp->offr) * sp->new_size) / sp->chunk;
	if (sp->txt_f < 0)
		sp->txt_f = 0;
	if (sp->txt_f > sp->size - 1)
		sp->txt_f = sp->size - 1;
	(void)cub;
}

void	sprites_utils_5(t_cub *cub, t_sp *sp)
{
	sp->y = 0;
	sp->start_point = 0;
	sp->end_point = sp->size;
	sp->start_point = 0;
	sp->end_point = sp->size;
	sp->real_wall_ds = ft_abs(sp->offset_up - sp->offset_down);
	if (sp->offset_up < 0)
	{
		sp->start_point = (float)(ft_abs(sp->offset_up) * sp->size) \
		/ (float)sp->real_wall_ds;
		if (sp->offset_down > HEIGHT)
			sp->end_point = sp->size - ((float)(ft_abs(sp->offset_down \
			- HEIGHT) * sp->size) / (float)sp->real_wall_ds);
	}
	sp->new_size = ft_abs2(sp->start_point - sp->end_point);
	(void)cub;
}

void	sprites_utils_4(t_cub *cub, t_sp *sp, t_tex *tex)
{
	sp->i = 0;
	sp->size = tex->size;
	if (sp->offset_up < 0)
		sp->offup = (float)ft_abs(sp->offset_up) / (float)HEIGHT;
	else
		sp->offup = 0;
	if (sp->offset_down > HEIGHT)
		sp->offdo = (float)ft_abs(sp->offset_down - HEIGHT) / (float)HEIGHT;
	else
		sp->offdo = 0;
	sp->offset = (sp->offup) * ((float)sp->r_wall_len);
	sp->initial = sp->screenx - ((float)(sp->r_wall_len) / (float)2.35);
	sp->chunk = (sp->r_wall_len * 0.85);
	sp->final = sp->initial + sp->chunk;
	(void)cub;
}
