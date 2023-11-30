/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:53:03 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 13:11:35 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static void	put_hand(t_cub *cub, int x, int y)
{
		cub->handx = x;
		cub->handy = y;
}

void	hand_loop(t_cub *cub)
{
	static int x = 0;
	static int sign = 1;

	if (x >= 5 || x < 0)
		sign *= -1;
	if (x == 0)
		put_hand(cub, 0, -10);
	else if (x == 1)
		put_hand(cub, 2, 2);
	else if (x == 2)
		put_hand(cub, 4, 2);
	else if (x == 3)
		put_hand(cub, 6, 2);
	else if (x == 4)
		put_hand(cub, 8, 0);
	else if (x == 5)
		put_hand(cub, 10, -10);
	x += sign;
}
