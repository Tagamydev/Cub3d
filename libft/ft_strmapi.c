/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:54:40 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/02 15:59:10 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*str;

	i = 0;
	str = ft_strdup((char *)s);
	if (!str)
		return (0);
	while (str[i])
	{
		str[i] = f(i, str[i]);
		++i;
	}
	return (str);
}
