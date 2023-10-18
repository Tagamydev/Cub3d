/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:58:10 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/09 13:39:08 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (n <= 0)
		return (dest);
	n = n - 1;
	while (i <= (int)n)
	{
		(*(char *)(dest + i) = *(char *)(src + i));
		++i;
	}
	return (dest);
}
