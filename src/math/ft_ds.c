/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:06:07 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:06:18 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

double	ft_ds(double xi, double xf, double yi, double yf)
{
	double	result;

	result = sqrt(pow((xi - xf), 2) + \
	pow((yi - yf), 2));
	return (result);
}
