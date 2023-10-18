/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:05:05 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/02 16:25:03 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_naruto(const char *s, int c, int i, int v)
{
	c = (char)c;
	while (*(const char *)(s + i))
		++i;
	if (!c)
	{
		while (*(const char *)(s + v))
			++v;
		return ((char *)s + v);
	}
	while ((s + i) >= (s + 0))
	{
		if (*(const char *)(s + i) == c)
		{
			v = 1;
			break ;
		}
		--i;
	}
	if (v == 0)
		return (0);
	return ((char *)s + i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		v;

	i = 0;
	v = 0;
	return (ft_naruto(s, c, i, v));
}
