/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:16:45 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:58:52 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	start_controls(t_cub *cub)
{
	mlx_hook(cub->win, 17, 0, (int (*)())close_x, cub);
	mlx_hook(cub->win, 2, 0, (int (*)())key_press, cub);
	mlx_hook(cub->win, 6, 0, (int (*)())mouse_location, cub);
	mlx_hook(cub->win, 4, 0, (int (*)())mouse_press, cub);
	mlx_hook(cub->win, 5, 0, (int (*)())mouse_release, cub);
	mlx_loop_hook(cub->mlx, (int (*)())frame, cub);
	return ;
}
