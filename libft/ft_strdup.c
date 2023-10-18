/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:45:19 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/09 13:37:09 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*s1c;
	int		i;

	i = 0;
	s1c = (char *)s1;
	str = (char *)malloc(sizeof(*s1c) * (ft_strlen(s1c) + 1));
	if (!s1 || !str)
		return (0);
	while (i < (int)ft_strlen(s1c))
	{
		str[i] = s1c[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
