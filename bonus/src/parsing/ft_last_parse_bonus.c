/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:59:16 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 21:31:00 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	ft_last_parse(t_cub *cub)
{
	cub->miniscreen_s = ft_init_img(cub->mlx, 62, 45);
	cub->miniscreen_m = ft_init_img(cub->mlx, 92, 65);
	return (1);
}
