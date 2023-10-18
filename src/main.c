/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:17:36 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 18:35:33 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	leaks(void)
{
	system("leaks fdf");
}

t_fdfc	*ft_set_up(char *str)
{
	t_fdfc		*fdf;
	t_height	*map;
	int			width;
	int			height;

	map = ft_make_map(str);
	ft_init_fdf(&fdf, str);
	fdf->map = malloc(sizeof(t_mapi));
	if (!fdf->map)
		ft_error_log("MALLOC_MAPI");
	fdf->map->map = map;
	width = ft_get_lenght("W", fdf->map->map);
	height = ft_get_lenght("H", fdf->map->map);
	fdf->map->height = height;
	fdf->map->width = width;
	fdf->camera->zoom = ft_min((WIDTH / width / 2), (HEIGHT / height / 2));
	return (fdf);
}

void	ft_controls(t_fdfc *fdf)
{
	mlx_hook(fdf->win, 17, 0, (int (*)())ft_close, fdf);
	mlx_hook(fdf->win, 2, 0, (int (*)())ft_key_press, fdf);
	mlx_loop_hook(fdf->mlx, (int (*)())ft_counter, fdf);
	return ;
}

int	main(int argc, char **argv)
{
	t_fdfc		*fdf;

	atexit(leaks);
	fdf = NULL;
	if (argc == 2)
	{
		fdf = ft_set_up(argv[1]);
		ft_ft_draw(fdf);
		ft_controls(fdf);
		mlx_loop(fdf->mlx);
	}
	ft_printf("usage: ./fdf 'map.fdf'\n");
	exit(0);
	return (0);
}
