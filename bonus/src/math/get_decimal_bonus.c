/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:55:33 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 11:55:49 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

double	get_decimal(double x)
{
	float	y;
	double	result;

	y = (int)x;
	result = (x * 10) - (y * 10);
	result = result / 10;
	return (result);
}
