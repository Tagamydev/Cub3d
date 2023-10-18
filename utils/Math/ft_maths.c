/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:23:29 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 18:27:45 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_maths.h>

int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	ft_lineal_mix(int c1, int c2, double mix)
{
	return (c1 * (1 - mix) + c2 * mix);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

double	ft_distance_2_points(t_point a, t_point b)
{
	double	x;
	double	y;

	x = pow((b.x - a.x), 2);
	y = pow((b.y - a.y), 2);
	return (sqrt(x + y));
}

int	ft_random(unsigned char seed)
{
	static unsigned char	current;
	unsigned char			tmp;

	if (seed != 0)
	{
		tmp = current;
		current = (unsigned char)seed;
	}
	else
		tmp = 0;
	current = (23 * current + 42 - (tmp / 3)) % 342;
	return (current);
}
