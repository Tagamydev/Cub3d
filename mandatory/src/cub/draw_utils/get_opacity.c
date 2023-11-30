/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opacity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:58:21 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 11:58:34 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

double	get_opacity(int color)
{
	int		bite;
	double	result;

	bite = ((color >> 24) & 0xFF);
	result = ft_fit_char(bite, 0, 1);
	return (result);
}
