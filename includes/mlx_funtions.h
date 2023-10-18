/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funtions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:58:51 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/18 10:49:24 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MLX_FUNTIONS_H
# define MLX_FUNTIONS_H
# include <mlx.h>
# include <math.h>
# include <libft.h>
# include <ft_maths.h>
# if !defined WIDTH
#  define WIDTH 1920
# endif
# if !defined HEIGTH
#  define HEIGHT 1080
# endif

struct s_points;

typedef struct s_img{
	void	*img;
	char	*data_addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	double	transparency;
	int		width;
	int		height;
}				t_img;

typedef struct s_bb{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
	struct s_points	line;
}				t_bb;


//=========================================================================//
//===============================FT_MLX====================================//
void		ft_put_pixel(t_img *img, int x, int y, int color);
t_img		*ft_init_img(void *mlx, t_img *img, int width, int height);
void		ft_fill_img(t_img *img, int color);
int			ft_get_color(int color, char *str);
int			ft_mix_color(int color1, int color2, double tr);
t_img		*ft_open_img(void *mlx, t_img *img, char *path);
int			ft_make_translucid(int color1);
int			ft_color_degradade(t_point init, t_point end, t_point current);
//=========================================================================//
//=============================BRENSENHAM==================================//
void		ft_clone(t_point *point, t_points line, int x, int y);
void		ft_draw_pixel(t_point point, t_img *img);
void		ft_put_line(t_point f, t_point s, t_img *map_display);
//=========================================================================//
//=========================================================================//


#endif
