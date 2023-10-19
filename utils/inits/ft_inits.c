/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:32:29 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/19 10:50:10 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

t_camera	*ft_init_cam(void)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		ft_error_log("MALLOC_CAMERA");
	camera->zoom = 1;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = -1.55;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}

static void	ft_init_util(t_cub *cub)
{
	cub->angle.projection = ISO_GAMES;
	cub->angle.angle = ft_get_angle(cub);
	cub->translation = 1;
	cub->play = 0;
}

void	ft_init_fdf(t_cub **cubp, char *title)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
		ft_error_log("MALLOC_cub");
	cub->mlx = mlx_init();
	if (!cub->mlx)
		ft_error_log("MLX_INIT");
	title = ft_map_format(title);
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, title);
	free(title);
	if (!cub->win)
		ft_error_log("MLX_WIN");
	ft_init_img(cub->mlx, &cub->map_display, WIDTH, HEIGHT);
	if (!cub->map_display.img)
		ft_error_log("INIT_MAP_DISPLAY");
	ft_fill_img(&cub->map_display, 0xFF000000);
	ft_init_img(cub->mlx, &cub->background, WIDTH, HEIGHT);
	if (!cub->background.img)
		ft_error_log("INIT_MAP_DISPLAY");
	ft_fill_img(&cub->background, 0x00000000);
	cub->camera = ft_init_cam();
	ft_init_util(cub);
	*cubp = cub;
	return ;
}
