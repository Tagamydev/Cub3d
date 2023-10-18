/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:50:10 by samusanc          #+#    #+#             */
/*   Updated: 2023/06/28 16:33:35 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	str = (char *)s;
	while (str[i] != '\0')
		++i;
	return (i);
}
