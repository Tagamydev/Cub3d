/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:58:53 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/02 13:50:23 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_make_str(size_t len, char *sc, char *str)
{
	size_t		i;

	i = 0;
	while (sc[i] && i < len)
	{
		str[i] = sc[i];
		++i;
	}
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		max_l;

	if (!s || !*s || start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	max_l = ft_strlen((char *)s) - start;
	if (len > max_l)
		len = max_l;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	return (ft_make_str(len, (char *)(s + start), str));
}
/*
int	main()
{
	printf("%s", ft_substr("", 5, 5));
}*/
