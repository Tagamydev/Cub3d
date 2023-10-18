/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:25:14 by samusanc          #+#    #+#             */
/*   Updated: 2023/06/05 17:28:40 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_if_convert(char c);
static void	ft_convert_and_write(char *string, int *i, \
va_list *values, int *general_counter);
int			ft_printf(char const *format, ...);

int	ft_printf(char const *format, ...)
{
	char	*string;
	va_list	values;
	int		i;
	int		general_counter;

	string = (char *)format;
	va_start (values, format);
	i = 0;
	general_counter = 0;
	while (string[i])
	{
		if ((char)string[i] == '%')
		{
			if (ft_if_convert(string[i + 1]))
				ft_convert_and_write(string, &i, &values, &general_counter);
		}
		else
			ft_format_char(string[i], &general_counter);
		++i;
	}
	va_end(values);
	return (general_counter);
}

static int	ft_if_convert(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (2);
	if (c == 'p')
		return (3);
	if (c == 'd')
		return (4);
	if (c == 'i')
		return (5);
	if (c == 'u')
		return (6);
	if (c == 'x')
		return (7);
	if (c == 'X')
		return (8);
	if (c == '%')
		return (9);
	return (0);
}

static void	ft_convert_and_write(char *string, int *i, \
va_list *values, int *general_counter)
{
	if (ft_if_convert(string[*i + 1]) == 1)
		ft_format_char((char)va_arg(*values, int), general_counter);
	if (ft_if_convert(string[*i + 1]) == 2)
		ft_format_string(va_arg(*values, char *), general_counter);
	if (ft_if_convert(string[*i + 1]) == 3)
		ft_format_hex(values, general_counter, string[*i + 1]);
	if (ft_if_convert(string[*i + 1]) == 4)
		ft_format_numbers(values, general_counter, string[*i + 1]);
	if (ft_if_convert(string[*i + 1]) == 5)
		ft_format_numbers(values, general_counter, string[*i + 1]);
	if (ft_if_convert(string[*i + 1]) == 6)
		ft_format_numbers(values, general_counter, string[*i + 1]);
	if (ft_if_convert(string[*i + 1]) == 7)
		ft_format_hex(values, general_counter, string[*i + 1]);
	if (ft_if_convert(string[*i + 1]) == 8)
		ft_format_hex(values, general_counter, string[*i + 1]);
	if (ft_if_convert(string[*i + 1]) == 9)
		ft_format_char('%', general_counter);
	++*i;
}
