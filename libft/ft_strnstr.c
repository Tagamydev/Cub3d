/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:00:50 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/02 16:11:07 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*a;
	char	*b;
	size_t	i;

	a = (char *)haystack;
	b = (char *)needle;
	i = 0;
	if (*b == '\0')
		return (a);
	if (len == 0)
		return (0);
	if (ft_strlen(b) > ft_strlen(a))
		return (0);
	while (a[0] != '\0' && i < len)
	{
		if (ft_strncmp(a, b, ft_strlen(b)) == 0)
			break ;
		++a;
		++i;
	}
	if (ft_strlen(b) + i > len)
		return (0);
	return (a);
}
