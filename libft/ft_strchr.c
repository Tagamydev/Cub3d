/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:50:44 by samusanc          #+#    #+#             */
/*   Updated: 2023/02/12 12:09:25 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		v;
	char	t;

	i = 0;
	v = 0;
	t = (char)c;
	if (t == '\0')
	{
		while (*(const char *)(s + v) != '\0')
			++v;
		return ((char *)s + v);
	}
	while (*(const char *)(s + i) != '\0')
	{
		if (*(const char *)(s + i) == t)
		{
			v = 1;
			break ;
		}
		++i;
	}
	if (v == 0)
		return (0);
	return ((char *)s + i);
}
