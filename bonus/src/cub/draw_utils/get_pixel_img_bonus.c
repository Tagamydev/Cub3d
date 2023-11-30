/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:54:35 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 13:34:58 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub.h>

int	get_pixel_img(t_img *img, int x, int y)
{
	return (*(unsigned int *)((img->data_addr + \
	(y * img->line_size) + (x * img->bits_per_pixel / 8))));
}
