/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:19:24 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/09 13:38:49 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	int		i;

	if (!str1 && !str2)
		return (NULL);
	if (str1 < str2)
	{
		i = -1;
		while (++i < (int)n)
			*(char *)(str1 + i) = *(char *)(str2 + i);
	}
	else
	{
		i = (int)n;
		while (--i >= 0)
			*(char *)(str1 + i) = *(char *)(str2 + i);
	}
	return (str1);
}
