/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:23:09 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/09 13:39:27 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sc;
	int				i;

	i = 0;
	sc = (unsigned char *)s;
	if (n != 0)
	{		
		while (i < (int)n)
		{
			if (*sc == (unsigned char)c)
				return (sc);
			++i;
			++sc;
		}
	}
	return (0);
}
