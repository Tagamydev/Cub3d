/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:19:52 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/02 16:09:07 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		r;
	int		s;

	str = (char *)nptr;
	r = 0;
	s = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45)
		s = -s;
	if (*str == 45 || *str == 43)
		str++;
	while (*str >= 48 && *str <= 57)
		r = (r * 10) + (*str++ - '0');
	return (r * s);
}

/*int	main(void)
{
	printf("atoi:%d\n", ft_atoi("    -2147483647"));
}
*/
