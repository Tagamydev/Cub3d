/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:46:28 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/12 19:49:53 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	long			len;

	len = ft_strlen((char *)src);
	if (dstsize > 0)
	{
		if (dst > src)
		{
			i = -1;
			while (++i < (dstsize - 1) && i < (unsigned long)(len))
				*(char *)(dst + i) = *(const char *)(src + i);
			*(char *)(dst + i) = '\0';
			return (len);
		}
		else
		{
			i = -1;
			while (++i < (dstsize - 1) && i < (unsigned long)(len))
				*(char *)(dst + i - 1) = *(const char *)(src + i);
			*(char *)(dst + i) = '\0';
			return (0);
		}
	}
	else
		return (len);
}
