/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:58:04 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/29 20:02:42 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	start_loop(t_cub *cub)
{
	mlx_loop(cub->mlx);
	return ;
	(void)cub;
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = NULL;
	if (argc != 2)
	{
		ft_perror(WRONG_ARGUMENTS);
		exit(-1);
	}
	else
	{
		cub = map_parsing(argv[1]);
		if (!cub)
			exit(-1);
		start_cub(cub);
		start_controls(cub);
		start_loop(cub);
	}
	exit(0);
}
