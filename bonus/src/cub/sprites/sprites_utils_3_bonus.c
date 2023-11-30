/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:58:24 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 18:58:37 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	sprites_utils_16(t_cub *cub, t_sp *sp, t_tex *tex)
{
	if (!sp->translucid)
	{
		if (cub->cam_status == OFF)
			sp->shadow = 17;
		else
			sp->shadow = 30;
		sp->shadow = sp->ds / sp->shadow;
		if (sp->shadow >= 1)
			sp->shadow = 1;
		sp->color = ft_mix_color(sp->color, 0x00000000, sp->shadow);
	}
	(void)tex;
	(void)cub;
}

void	sprites_utils_15(t_cub *cub, t_sp *sp, t_tex *tex)
{
	sp->u = sp->j + sp->k;
	if (sp->u > WIDTH - 1)
		sp->u = WIDTH - 1;
	if (sp->u < 0)
		sp->u = 0;
	sp->tmp1 = cub->screen[sp->i][sp->u];
	(void)tex;
	(void)cub;
}

void	sprites_utils_14(t_cub *cub, t_sp *sp, t_tex *tex)
{
	if (sp->color == 0x00FF00FF)
	{
		sp->translucid = 1;
		sp->tmp = sp->j + sp->k;
		if (sp->tmp < 0)
			sp->tmp = 0;
		if (sp->tmp > WIDTH - 1)
			sp->tmp = 0;
		sp->color = get_pixel_img(cub->game, sp->tmp, sp->i);
	}
	(void)tex;
	(void)cub;
}
