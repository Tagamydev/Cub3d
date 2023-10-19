/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:17:36 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/19 10:46:09 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	leaks(void)
{
	system("leaks fdf");
}

t_cub	*ft_set_up(char *str)
{
	t_cub		*cub;
	t_height	*map;
	int			width;
	int			height;

	map = ft_make_map(str);
	ft_init_fdf(&cub, str);
	cub->map = malloc(sizeof(t_mapi));
	if (!cub->map)
		ft_error_log("MALLOC_MAPI");
	cub->map->map = map;
	width = ft_get_lenght("W", cub->map->map);
	height = ft_get_lenght("H", cub->map->map);
	cub->map->height = height;
	cub->map->width = width;
	cub->camera->zoom = ft_min((WIDTH / width / 2), (HEIGHT / height / 2));
	return (cub);
}

void	ft_controls(t_cub *cub)
{
	mlx_hook(cub->win, 17, 0, (int (*)())ft_close, cub);
	mlx_hook(cub->win, 2, 0, (int (*)())ft_key_press, cub);
	mlx_loop_hook(cub->mlx, (int (*)())ft_counter, cub);
	return ;
}

int	main(int argc, char **argv)
{
	t_cub		*cub;

	atexit(leaks);
	cub = NULL;
	if (argc == 2)
	{
		cub = ft_set_up(argv[1]);
		ft_ft_draw(cub);
		ft_controls(cub);
		mlx_loop(cub->mlx);
	}
	ft_printf("usage: ./cub 'map.cub'\n");
	exit(0);
	return (0);
}
