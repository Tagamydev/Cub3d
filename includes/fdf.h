/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:14:03 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/18 10:50:38 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <libft.h>
# include <ft_error.h>
# include <mlx_funtions.h>
# define BASE_UP "0123456789ABCDEF"
# define BASE_LOW "0123456789abcdef"
# define ERROR_INVALID_MAP "INVALID_MAP\nMake sure the .fdf file has permissions"
# define WIDTH 1920
# define HEIGHT 1080

/*
typedef enum e_projection{
	ISO,
	ISO_GAMES,
	PARALLEL,
	CUSTOM,
	CONIC,
	TOTAL
}		t_projection;

typedef struct s_angle{
	t_projection	projection;
	double			angle;
}				t_angle;

typedef struct s_camera{
	t_projection	projection;
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_divisor;
	int				x_offset;
	int				y_offset;
}				t_camera;

typedef struct s_width{
	int				z;
	int				color;
	struct s_width	*next;
}				t_width;

typedef struct s_height{
	t_width			*line;
	struct s_height	*next;
}				t_height;

typedef struct s_mapi{
	t_height	*map;
	int			height;
	int			width;
}				t_mapi;

typedef struct s_fdf{
	void			*mlx;
	void			*win;
	t_mapi			*map;
	t_img			map_display;
	t_img			background;
	t_camera		*camera;
	t_height		*grid;
	t_angle			angle;
	double			translation;
	unsigned char	random;
	int				play;
}				t_fdfc;
*/

/*
//-------------------------|	Memory, leaks and errors	|-----------------//
void		ft_error_log(char *str);
int			ft_free_string(char **split);
int			ft_free_split(char **split);
//-------------------------|	Gnl copy 	|---------------------------------//
char		*get_all_doc(int fd);
//-------------------------|	Parse	|-------------------------------------//
int			ft_get_lenght(char *str, t_height *map);
int			ft_is_digit_base(char c, int base, char *digits);
int			ft_atoi_base_hex(char *number, int base);
int			ft_atoi_base(char *number, int base);
int			ft_is_number_or_color(char **numb);
char		*ft_map_format(char *str);
t_width		*ft_new_column_node(char *str);
void		ft_atach_column(t_width **list, t_width *node);
t_height	*ft_new_height_node(char *str);
void		ft_atach_line(t_height **list, t_height *node);
t_height	*ft_init_height(char *doc);
void		ft_prove_map(t_height *map);
t_height	*ft_make_map(char *str);
void		ft_print_line_map(t_width *line, int y);
void		ft_print_mapi(t_height *map);
void		ft_free_line_map(t_width *map);
void		ft_free_map(t_height *map);
//-------------------------|	Math	|-------------------------------------//
double		ft_get_angle(t_fdfc *fdf);
void		ft_rotate_x(int *y, int *z, double alpha);
void		ft_rotate_y(int *x, int *z, double beta);
void		ft_rotate_z(int *x, int *y, double gamma);
void		ft_iso(int *x, int *y, int z, t_fdfc *fdf);
int			ft_random(unsigned char seed);
void		ft_make_maths(t_point *point, t_fdfc *fdf);
//-------------------------|	Get point	|---------------------------------//
int			ft_get_col(t_height *map, int x, int y);
int			ft_get_z(t_height *map, int x, int y);
t_point		*ft_get_point(t_height *map, int x, int y);
//-------------------------|	Inits	|-------------------------------------//
t_camera	*ft_init_cam(void);
void		ft_init_fdf(t_fdfc **fdfp, char *title);
//-------------------------|	Render	|-------------------------------------//
t_point		ft_proyect_minimap(t_point *point, t_fdfc *fdf);
t_point		ft_proyect(t_point *point, t_fdfc *fdf);
void		ft_ft_draw(t_fdfc *fdf);
//-------------------------|	Keys	|-------------------------------------//
void		ft_close(void *param);
void		ft_change_proyection(t_fdfc *fdf);
int			ft_rotate(int key, t_fdfc *fdf);
int			ft_key_press(int key, void *param);
void		ft_counter(void *param);
//-------------------------|	MAIN	|-------------------------------------//
void		ft_controls(t_fdfc *fdf);
t_fdfc		*ft_set_up(char *str);
int			main(int argc, char **argv);
*/

#endif
