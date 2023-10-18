/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_funtions_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:32:24 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 18:36:39 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx_funtions.h>

int	ft_get_color(int color, char *str)
{
	if (*str == 'T')
		return ((color >> 24) & 0xFF);
	if (*str == 'R')
		return ((color >> 16) & 0xFF);
	if (*str == 'G')
		return ((color >> 8) & 0xFF);
	if (*str == 'B')
		return ((color) & 0xFF);
	return (0);
}

int	ft_mix_color(int color1, int color2, double tr)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	t = ft_lineal_mix(ft_get_color(color1, "T"), \
	ft_get_color(color2, "T"), tr);
	r = ft_lineal_mix(ft_get_color(color1, "R"), \
	ft_get_color(color2, "R"), tr);
	g = ft_lineal_mix(ft_get_color(color1, "G"), \
	ft_get_color(color2, "G"), tr);
	b = ft_lineal_mix(ft_get_color(color1, "B"), \
	ft_get_color(color2, "B"), tr);
	return (t << 24 | r << 16 | g << 8 | b);
}

t_img	*ft_open_img(void *mlx, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img)
		ft_error_log("IMG_OPEN_ME_CAGO_EN_TUS_MUERTOS");
	return (img);
}

int	ft_make_translucid(int color1)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 255;
	r = ft_get_color(color1, "R");
	g = ft_get_color(color1, "G");
	b = ft_get_color(color1, "B");
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_color_degradade(t_point init, t_point end, t_point current)
{
	double	total_distance;
	double	actual_distance;
	double	result;

	total_distance = ft_distance_2_points(init, end);
	actual_distance = ft_distance_2_points(init, current);
	result = actual_distance / total_distance;
	return (ft_mix_color(init.color, end.color, result));
}
