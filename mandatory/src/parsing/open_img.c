/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:19:48 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/30 19:53:06 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	open_img_cero(t_cub *cub)
{
	cub->nina_cam[0][0] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/nbk/f1.xpm");
	if (!cub->nina_cam[0][0])
		return (0);
	cub->nina_cam[0][1] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/nbk/f2.xpm");
	if (!cub->nina_cam[0][1])
		return (0);
	cub->nina_cam[0][2] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/nbk/f3.xpm");
	if (!cub->nina_cam[0][2])
		return (0);
	cub->nina_cam[0][3] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/nbk/f4.xpm");
	if (!cub->nina_cam[0][3])
		return (0);
	cub->nina_cam[0][4] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/nbk/f5.xpm");
	if (!cub->nina_cam[0][4])
		return (0);
	return (1);
}

int	open_img_one(t_cub *cub)
{
	cub->nina_cam[1][0] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/mbk/f1.xpm");
	if (!cub->nina_cam[1][0])
		return (0);
	cub->nina_cam[1][1] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/mbk/f2.xpm");
	if (!cub->nina_cam[1][1])
		return (0);
	cub->nina_cam[1][2] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/mbk/f3.xpm");
	if (!cub->nina_cam[1][2])
		return (0);
	cub->nina_cam[1][3] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/mbk/f4.xpm");
	if (!cub->nina_cam[1][3])
		return (0);
	cub->nina_cam[1][4] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/mbk/f5.xpm");
	if (!cub->nina_cam[1][4])
		return (0);
	return (1);
}

int	open_img_two(t_cub *cub)
{
	cub->nina_cam[2][0] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/bk/f1.xpm");
	if (!cub->nina_cam[2][0])
		return (0);
	cub->nina_cam[2][1] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/bk/f2.xpm");
	if (!cub->nina_cam[2][1])
		return (0);
	cub->nina_cam[2][2] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/bk/f3.xpm");
	if (!cub->nina_cam[2][2])
		return (0);
	cub->nina_cam[2][3] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/bk/f4.xpm");
	if (!cub->nina_cam[2][3])
		return (0);
	cub->nina_cam[2][4] = ft_open_img(cub->mlx,
			"./src/img/nina/ncam/bk/f5.xpm");
	if (!cub->nina_cam[2][4])
		return (0);
	return (1);
}

int	open_img_all(t_cub *cub)
{
	cub->nina_ncam[0] = ft_open_img(cub->mlx, "./src/img/nina/cam/f1.xpm");
	if (!cub->nina_ncam[0])
		return (0);
	cub->nina_ncam[1] = ft_open_img(cub->mlx, "./src/img/nina/cam/f2.xpm");
	if (!cub->nina_ncam[1])
		return (0);
	cub->nina_ncam[2] = ft_open_img(cub->mlx, "./src/img/nina/cam/f3.xpm");
	if (!cub->nina_ncam[2])
		return (0);
	cub->nina_ncam[3] = ft_open_img(cub->mlx, "./src/img/nina/cam/f4.xpm");
	if (!cub->nina_ncam[3])
		return (0);
	cub->nina_ncam[4] = ft_open_img(cub->mlx, "./src/img/nina/cam/f5.xpm");
	if (!cub->nina_ncam[4])
		return (0);
	return (1);
}

int	open_all_img(t_cub *cub)
{
	cub->black = ft_open_img(cub->mlx, "./src/img/black.xpm");
	if (!cub->no_texture)
		return (0);
	if (!open_img_cero(cub))
		return (0);
	if (!open_img_one(cub))
		return (0);
	if (!open_img_two(cub))
		return (0);
	if (!open_img_all(cub))
		return (0);
	return (1);
}
