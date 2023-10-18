/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:21:41 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/09 13:39:55 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		++i;
	while (n)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nf;
	int		l;
	char	*str;

	nf = (long)n;
	l = ft_intlen(n);
	str = malloc (sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	if (nf < 0)
		nf = -nf;
	str[l] = '\0';
	while (l--)
	{
		str[l] = (nf % 10) + '0';
		nf = nf / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
