/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:50:49 by samusanc          #+#    #+#             */
/*   Updated: 2023/06/11 10:17:42 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static int	ft_print_null(void)
{
	if (write(1, "(null)", 6) < 0)
		return (-1);
	return (6);
}

static void	ft_sum_general_count(int *i)
{
	if (*i == -1)
		return ;
	++*i;
}

int	ft_format_string(char *s, int *general_count)
{
	int	i;

	i = 0;
	if (!s)
	{
		*general_count = *general_count + ft_print_null();
		return (0);
	}
	while (s[i])
	{
		if (write(1, &s[i++], 1) < 0)
			return (-1);
		ft_sum_general_count(general_count);
	}
	return (0);
}
