/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:04:08 by samusanc          #+#    #+#             */
/*   Updated: 2023/06/11 10:17:30 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static void	ft_sum_general_count(int *i)
{
	if (*i == -1)
		return ;
	++*i;
}

int	ft_format_char(char c, int *general_count)
{
	if (write(1, &c, 1) < 0)
		*general_count = -1;
	ft_sum_general_count(general_count);
	return (0);
}
