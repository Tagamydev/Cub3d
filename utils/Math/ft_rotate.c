/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:27:23 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 18:29:04 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

double	ft_get_angle(t_fdfc *fdf)
{
	if (fdf->angle.projection == ISO)
		return (0.523599);
	if (fdf->angle.projection == ISO_GAMES)
		return (0.463646716);
	if (fdf->angle.projection == CONIC)
		return (0.785398);
	if (fdf->angle.projection == CUSTOM)
		return (fdf->angle.angle);
	return (0);
}

void	ft_rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	ft_rotate_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void	ft_rotate_z(int *x, int *y, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void	ft_iso(int *x, int *y, int z, t_fdfc *fdf)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(ft_get_angle(fdf));
	*y = -z + (tmp_x + tmp_y) * sin(ft_get_angle(fdf));
	z = 0;
}
