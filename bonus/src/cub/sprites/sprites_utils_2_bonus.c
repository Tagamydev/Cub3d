/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:57:48 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 19:02:13 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	sprites_utils_13(t_cub *cub, t_sp *sp, t_tex *tex)
{
	if (sp->x < 0)
		sp->x = 0;
	if (sp->x > sp->size - 1)
		sp->x = sp->size - 1;
	sp->y2 = (sp->y * sp->new_size) / sp->wall_len;
	sp->y2 += sp->start_point;
	if (sp->y2 < 0)
		sp->y2 = 0;
	if (sp->y2 > sp->size - 1)
		sp->y2 = sp->size - 1;
	sp->color = tex->tex[(int)sp->y2][(int)sp->x];
	(void)tex;
	(void)cub;
}

void	sprites_utils_12(t_cub *cub, t_sp *sp, t_tex *tex)
{
	sprites_utils_13(cub, sp, tex);
	sprites_utils_14(cub, sp, tex);
	sprites_utils_15(cub, sp, tex);
	sprites_utils_16(cub, sp, tex);
	if (sp->tmp1 > sp->ds)
	{
		ft_put_pixel(cub->game, sp->j + sp->k, sp->i, sp->color);
		if (!sp->translucid)
			cub->screen[sp->i][sp->u] = sp->ds;
	}
	(void)tex;
	(void)cub;
}

void	sprites_utils_11(t_cub *cub, t_sp *sp, t_tex *tex)
{
	if (sp->k % 3 == 0)
		sp->zz = 0;
	else
		sp->zz = 1;
	if (cub->cam_status == ON)
		sp->zz = 1;
	sp->translucid = 0;
	(void)tex;
	(void)cub;
}

void	sprites_utils_10(t_cub *cub, t_sp *sp, t_tex *tex)
{
	while (sp->k < (sp->r_wall_len * 0.85) && (sp->k < WIDTH * 4))
	{
		sprites_utils_11(cub, sp, tex);
		if (sp->i > sp->offset_up && sp->i \
		< sp->offset_down && (sp->zz && sp->zx))
			sprites_utils_12(cub, sp, tex);
		sp->x += sp->chunk;
		sp->k++;
	}
	(void)tex;
}

void	sprites_utils_9(t_cub *cub, t_sp *sp, t_tex *tex)
{
	sp->x = sp->txt_i;
	sp->j = sp->initial;
	sp->k = 0;
	if (sp->i > sp->offset_up && sp->i < sp->offset_down)
		sp->y++;
	if (sp->i % 3 == 0)
		sp->zx = 0;
	else
		sp->zx = 1;
	if (cub->cam_status == ON)
		sp->zx = 1;
	(void)tex;
}
