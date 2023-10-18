/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:22:11 by samusanc          #+#    #+#             */
/*   Updated: 2023/01/30 14:22:18 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*c;
	unsigned char	*b;

	i = 0;
	c = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (!n)
		return (0);
	while (i < (int)n)
	{
		if (c[i] != b[i])
			return (c[i] - b[i]);
		i++;
	}
	return (0);
}
