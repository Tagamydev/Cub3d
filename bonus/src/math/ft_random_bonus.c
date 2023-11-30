/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:57:21 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 11:57:33 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

float	ft_random(float n, float min, float max)
{
	int				i;
	size_t			j;
	int				fd;
	static int		decimals;
	static double	result = 7;

	fd = open("/dev/urandom", O_RDONLY);
	i = 0;
	j = 0;
	while (j < 3)
	{
		decimals = i;
		read(fd, &i, 1);
		j++;
	}
	result = ft_fit_char(decimals, 0, 1);
	result = ft_fit_char((float)i + result, min, max);
	close(fd);
	(void)n;
	return (result);
}
