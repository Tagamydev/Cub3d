/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:26:37 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/09 13:36:51 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_put_str(char *s1, char *s2)
{
	char				*str;
	unsigned int		l1;
	unsigned int		l2;

	l1 = -1;
	l2 = -1;
	str = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	while (s1[++l1])
	{
		str[l1] = s1[l1];
	}
	while (s2[++l2])
	{
		str[l1++] = s2[l2];
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (NULL);
	return (ft_put_str((char *)s1, (char *)s2));
}
/*
int	main()
{
	printf("%s", ft_strjoin("hola", "adeu"));
}*/
