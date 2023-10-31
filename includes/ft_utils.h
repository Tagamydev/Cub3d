/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:20:28 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/31 12:58:25 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdio.h>

typedef struct s_put_walls{
	int	i;
	int	j;
	int	minx;
	int	x2;
	int	y2;
}				t_put_walls;

typedef struct s_square{
	int	x;
	int	y;
	int len;
	int color;
}				t_square;

#endif

