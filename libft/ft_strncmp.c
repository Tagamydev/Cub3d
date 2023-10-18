/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:18:47 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/09 13:35:32 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s2[i] != '\0' && s1[i] != '\0') && (i < n - 1) && (s1[i] == s2[i]))
		++i;
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}
