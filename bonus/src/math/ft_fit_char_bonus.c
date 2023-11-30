/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:56:50 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 11:57:06 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

float	ft_fit_char(float n, float min, float max)
{
	float	range;
	float	result;

	range = ft_abs2(min - max);
	result = (float)(n * range) / (float)(255);
	result += min;
	return (result);
}
