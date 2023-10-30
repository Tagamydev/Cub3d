/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:16:45 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/30 14:26:48 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	close_x(void *param)
{
	(void)param;
	exit(1);
	return ;
}

void	open_doors(t_cub *cub, char *x)
{
	*x = 'O';
	printf("opening the doors\n");
	(void)cub;
}

void	close_doors(t_cub *cub, char *x)
{
	*x = 'C';
	printf("closing the doors\n");
	(void)cub;
}

void	key_press(int key, void *param)
{
	static char	door = 'C';
	t_cub		*cub;

	cub = (t_cub *)param;
	if (key == 53)
		close_x(param);
	else if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		;
	}
	else if (key == 49)
	{
		if (door == 'C')
			open_doors(cub, &door);
		else
			close_doors(cub, &door);
	}
	else if (key == 123 || key == 124)
	{
		;
	}
	start_cub(cub);
}

void	start_controls(t_cub *cub)
{
	mlx_hook(cub->win, 17, 0, (int (*)())close_x, cub);
	mlx_hook(cub->win, 2, 0, (int (*)())key_press, cub);
	return ;
	(void)cub;
}
