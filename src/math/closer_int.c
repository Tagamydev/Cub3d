/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closer_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:57:50 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 11:58:04 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

double	closer_int(double n)
{
	double decimal;
	double result;

	decimal = get_decimal(n);
	if (decimal == 0.5)
	{
		while (decimal == 0.5)
			decimal = get_decimal(n * 10);
	}
	if (decimal > 0.5)
		result = (int)n + 1;
	else
		result = (int)n;
	return (result);
}
