/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:20:28 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 13:45:26 by samusanc         ###   ########.fr       */
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

typedef struct s_sg{
	int		i;
	int		j;
	float	m;
	int		color;
	int		color1;
	int		color2;
	float	x;
	int		cam;
	int		ground;
}				t_sg;

#endif

