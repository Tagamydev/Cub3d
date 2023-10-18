/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:12:26 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 17:41:14 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

int	ft_is_digit_base(char c, int base, char *digits)
{
	int	i;

	i = 0;
	while (i < base)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base_hex(char *number, int base)
{
	int	result;

	result = 0;
	if (*number == '0' && *(number + 1) == 'x')
		number += 2;
	else
		ft_error_log("COLOR_FORMAT_ERROR_0x");
	while (ft_is_digit_base(*number, base, BASE_UP) != -1)
		result = result * base + ft_is_digit_base(*(number++), base, BASE_UP);
	if (*number && *number != '\n')
		ft_error_log("COLOR_FORMAT_ERROR_NULL");
	return (result);
}

int	ft_atoi_base(char *number, int base)
{
	int	result;
	int	sing;

	result = 0;
	sing = 1;
	if (base > 10)
		return (ft_atoi_base_hex(number, base));
	while (*number == ' ' || *number == '\t')
		number++;
	if (*number == '-')
		sing = -sing;
	if (*number == '-' || *number == '+')
		number++;
	while (*number >= '0' && *number <= '9')
		result = result * base + ft_is_digit_base(*(number++), 10, BASE_UP);
	if (*number && *number != '\n')
		ft_error_log("INVALID_MAP");
	return (sing * result);
}

int	ft_is_number_or_color(char **numb)
{
	if (!*numb)
		return (0);
	ft_atoi_base(*numb, 10);
	if (*(numb + 1))
		ft_atoi_base(*(numb + 1), 16);
	return (1);
}
