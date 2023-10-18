/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:21:36 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/18 10:48:25 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_MATHS_H
# define FT_MATHS_H
# include <math.h>
# include <ft_error.h>
# include <libft.h>

typedef struct s_point{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_points{
	t_point	start;
	t_point	end;
}				t_points;

int			ft_min(int x, int y);
int			ft_lineal_mix(int c1, int c2, double mix);
int			ft_abs(int x);
double		ft_distance_2_points(t_point a, t_point b);

#endif
