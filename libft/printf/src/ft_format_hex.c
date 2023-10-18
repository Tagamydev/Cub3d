/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:46:19 by samusanc          #+#    #+#             */
/*   Updated: 2023/06/05 18:22:34 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "formats.h"

static int	ft_format_x(unsigned int number, char *base, int *general_counter)
{
	char	result[20];
	int		i;

	i = 0;
	if (!number)
		return (ft_format_string("0", general_counter));
	while (i < 20)
		result[i++] = '\0';
	i = 0;
	while (number)
	{
		result[i++] = base[number % 16];
		number = number / 16;
	}
	*general_counter = *general_counter + i;
	--i;
	while (i >= 0)
		write (1, &result[i--], 1);
	return (0);
}

static int	ft_format_p(va_list *v, int *gn, char format, char *base)
{
	char	result[20];
	size_t	number;
	int		i;

	i = 0;
	if (format == 'X')
		return (ft_format_x(va_arg(*v, unsigned int), \
		"0123456789ABCDEF", gn));
	if (format == 'X' || format == 'x')
		return (ft_format_x(va_arg(*v, unsigned int), \
		base, gn));
	number = va_arg(*v, unsigned long);
	ft_format_string("0x", gn);
	if (!number)
		return (ft_format_string("0", gn));
	while (number)
	{
		result[i++] = base[number % 16];
		number = number / 16;
	}
	*gn = *gn + i;
	--i;
	while (i >= 0)
		write (1, &result[i--], 1);
	return (0);
}

int	ft_format_hex(va_list *values, int *general_counter, char format)
{
	return (ft_format_p(values, general_counter, format, "0123456789abcdef"));
}
