/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:25:43 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/09 13:36:30 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_chng_str(size_t i, size_t i3, const char *s, char *d)
{
	size_t	i4;
	size_t	i2;

	i2 = ft_strlen(d) + ft_strlen((char *)s);
	i4 = i2 - ft_strlen((char *)s);
	while (i4 < i - 1 && i3 < ft_strlen((char *)s))
	{
		d[i4] = s[i3];
		++i4;
		++i3;
	}
	d[i4] = '\0';
}

size_t	ft_strlcat(char *d, const char *src, size_t i)
{
	char		*s;
	size_t		i2;
	size_t		i3;

	s = (char *)src;
	if (!i)
		return (ft_strlen(s));
	i2 = ft_strlen(d) + ft_strlen(s);
	i3 = 0;
	if (i > ft_strlen(d))
	{
		ft_chng_str(i, i3, s, d);
		return (i2);
	}
	else if (i == 0)
	{
		return (ft_strlen(s));
	}
	return (ft_strlen(s) + i);
}
