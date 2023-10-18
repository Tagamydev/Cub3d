/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:54:09 by samusanc          #+#    #+#             */
/*   Updated: 2023/06/05 18:24:49 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "formats.h"
#include <stdarg.h>

static void	ft_format_unsigned(unsigned int number, int *general_counter)
{
	char	c;

	if (!number)
	{
		ft_format_char('0', general_counter);
		return ;
	}
	if (number < 10)
	{
		c = number + '0';
		ft_format_char(c, general_counter);
		return ;
	}
	else
	{
		c = (number % 10) + '0';
		ft_format_unsigned(number / 10, general_counter);
		ft_format_char(c, general_counter);
	}
}

static int	ft_format_int_and_decimal(int number, int *general_counter)
{
	char	c;

	if (number == -2147483648)
		return (ft_format_string("-2147483648", general_counter));
	if (number < 0)
	{
		number = number * -1;
		ft_format_char('-', general_counter);
	}
	if (!number)
		return (ft_format_char('0', general_counter));
	if (number < 10)
	{
		c = number + '0';
		return (ft_format_char(c, general_counter));
	}
	else
	{
		c = (number % 10) + '0';
		ft_format_int_and_decimal(number / 10, general_counter);
		ft_format_char(c, general_counter);
	}
	return (0);
}

void	ft_format_numbers(va_list *arguments, int *general_counter, char format)
{
	if (format == 'u')
		ft_format_unsigned(va_arg(*arguments, unsigned int), general_counter);
	else
		ft_format_int_and_decimal(va_arg(*arguments, int), general_counter);
}
