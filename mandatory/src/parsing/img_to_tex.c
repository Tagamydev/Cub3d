/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:28:10 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/30 19:53:13 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	img_to_tex_cero(t_cub *cub)
{
	cub->t_nina_cam[0][0] = img_to_tex(cub->nina_cam[0][0]);
	if (!cub->t_nina_cam[0][0])
		return (0);
	cub->t_nina_cam[0][1] = img_to_tex(cub->nina_cam[0][1]);
	if (!cub->t_nina_cam[0][1])
		return (0);
	cub->t_nina_cam[0][2] = img_to_tex(cub->nina_cam[0][2]);
	if (!cub->t_nina_cam[0][2])
		return (0);
	cub->t_nina_cam[0][3] = img_to_tex(cub->nina_cam[0][3]);
	if (!cub->t_nina_cam[0][3])
		return (0);
	cub->t_nina_cam[0][4] = img_to_tex(cub->nina_cam[0][4]);
	if (!cub->t_nina_cam[0][4])
		return (0);
	return (1);
}

int	img_to_tex_one(t_cub *cub)
{
	cub->t_nina_cam[1][0] = img_to_tex(cub->nina_cam[1][0]);
	if (!cub->t_nina_cam[1][0])
		return (0);
	cub->t_nina_cam[1][1] = img_to_tex(cub->nina_cam[1][1]);
	if (!cub->t_nina_cam[1][1])
		return (0);
	cub->t_nina_cam[1][2] = img_to_tex(cub->nina_cam[1][2]);
	if (!cub->t_nina_cam[1][2])
		return (0);
	cub->t_nina_cam[1][3] = img_to_tex(cub->nina_cam[1][3]);
	if (!cub->t_nina_cam[1][3])
		return (0);
	cub->t_nina_cam[1][4] = img_to_tex(cub->nina_cam[1][4]);
	if (!cub->t_nina_cam[1][4])
		return (0);
	return (1);
}

int	img_to_tex_two(t_cub *cub)
{
	cub->t_nina_cam[2][0] = img_to_tex(cub->nina_cam[2][0]);
	if (!cub->t_nina_cam[2][0])
		return (0);
	cub->t_nina_cam[2][1] = img_to_tex(cub->nina_cam[2][1]);
	if (!cub->t_nina_cam[2][1])
		return (0);
	cub->t_nina_cam[2][2] = img_to_tex(cub->nina_cam[2][2]);
	if (!cub->t_nina_cam[2][2])
		return (0);
	cub->t_nina_cam[2][3] = img_to_tex(cub->nina_cam[2][3]);
	if (!cub->t_nina_cam[2][3])
		return (0);
	cub->t_nina_cam[2][4] = img_to_tex(cub->nina_cam[2][4]);
	if (!cub->t_nina_cam[2][4])
		return (0);
	return (1);
}

int	img_to_tex_rest(t_cub *cub)
{
	cub->t_nina_ncam[0] = img_to_tex(cub->nina_ncam[0]);
	if (!cub->t_nina_ncam[0])
		return (0);
	cub->t_nina_ncam[1] = img_to_tex(cub->nina_ncam[1]);
	if (!cub->t_nina_ncam[1])
		return (0);
	cub->t_nina_ncam[2] = img_to_tex(cub->nina_ncam[2]);
	if (!cub->t_nina_ncam[2])
		return (0);
	cub->t_nina_ncam[3] = img_to_tex(cub->nina_ncam[3]);
	if (!cub->t_nina_ncam[3])
		return (0);
	cub->t_nina_ncam[4] = img_to_tex(cub->nina_ncam[4]);
	if (!cub->t_nina_ncam[4])
		return (0);
	return (1);
}

int	img_to_tex_all(t_cub *cub)
{
	if (!img_to_tex_cero(cub))
		return (0);
	if (!img_to_tex_one(cub))
		return (0);
	if (!img_to_tex_two(cub))
		return (0);
	if (!img_to_tex_rest(cub))
		return (0);
	return (1);
}
