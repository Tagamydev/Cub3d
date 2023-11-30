/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:08:36 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:19:40 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

t_win	tmp_win(void *mlx, void *win, t_img *result)
{
	t_win	final;

	final.mlx = mlx;
	final.win = win;
	final.result = result;
	return (final);
}
