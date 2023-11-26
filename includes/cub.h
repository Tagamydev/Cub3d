/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:59:01 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/26 11:47:56 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <mlx.h>
# include <math.h>
# include <ft_math.h>
# include <stdio.h>
# include <libft.h>
# include <ft_perror.h>
# include <ft_utils.h>
# include <bresenham.h>
# define WIDTH 640
# define HEIGHT 480
# define ZOOM_L 7
# define ZOOM_M 14
# define ZOOM_S 35
# define COLOR_W 0x8CFFFFFF
# define COLOR_E 0x8C000000
# define COLOR_D 0x8C00FF00
# define COLOR_P 0x8CFF0000
# define PI 3.1415926535
# define DR 0.0174533
# define SPEED 0.5
# define COSX cos(angle_to_radian(get_angle(ray_a)))
# define SINY sin(angle_to_radian(get_angle(ray_a)))
# define OFF 0
# define ON 1
# define FRONT 1
# define SIDE 0

typedef struct s_tex{
	int		**tex;
	size_t	size;
}				t_tex;
typedef struct s_img{
	void	*img;
	char	*data_addr;
	int		*pixel_addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	double	transparency;
	int		width;
	int		height;
}				t_img;

/*
 *		map notation
 *		1 wall
 *		0 empty
 *		2 player facing north
 *		3 player facing south
 *		4 player facing east
 *		5 player facing west
 *		6 door close
 *		7 door open
 *		8 player in door
 *		9 space in map
 */

typedef struct s_cub{
	//=========================//
	//        MAP_UTILS        //
	size_t	**map;
	//int		*map_4_ray;
	size_t	map_width;
	size_t	map_height;
	t_img	*no_texture;
	t_img	*so_texture;
	t_img	*ea_texture;
	t_img	*we_texture;
	t_img	*black;
	t_tex	*no_t;
	t_tex	*so_t;
	t_tex	*ea_t;
	t_tex	*we_t;
	t_tex	*black_t;
	int		color_ground;
	int		color_sky;
	int		door;
	//=========================//
	//        MLX_UTILS        //
	void	*mlx;
	void	*win;
//	void	*ray_win;
	t_img	*game;
	t_img	*cam;
	t_img	*atm;
	t_img	*hud_o;
	t_img	*hud_c;
	t_img	*hand;
	t_img	*hand_m;
	t_img	*hand_l;
	t_img	*noise1;
	t_img	*noise2;
	t_img	*noise3;
	t_img	*noise4;
	t_img	*noise5;
	t_img	*noise6;
	t_img	*minimap;
//	t_img	*ray_map;
	//=========================//
	//          PLAYER         //
	int		camera_speed;
	float	player_px;
	float	player_py;
	float	player_dx;
	float	player_dy;
	float	player_d2x;
	float	player_d2y;
	float	player_a;
	int		handx;
	int		handy;
	int		mousex;
	int		mousey;
	int		mouse_press;
	//=========================//
	//          MINIMAP        //
	int		minimap_zoom;
	//=========================//
	//           CAM           //
	int		fisheye;
	int		cam_status;
	size_t	frame;
	int		cam_animation;
}				t_cub;

typedef struct s_win{
	void	*mlx;
	void	*win;
	t_img	*result;
}				t_win;

typedef struct s_ray{
	float	x;
	float	y;
	float	angle;
	float	distance;
	float	color;
	float	shadow;
	int		side;
}				t_ray;

void	free_split(char **input);
double	angle_to_radian(double angle);
double	get_angle(double angle);
void	put_deltas(t_cub *cub);
int	get_pixel_img(t_img *img, int x, int y);
int	cub_open_utils(t_cub *cub);
//============================================================================//
//=================================MLX========================================//
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	ft_fill_img(t_img *img, int color);
t_img	*ft_init_img(void *mlx, int width, int height);
void	draw_square(t_img *img, t_square sq);
void	fill_img_sky_n_ground(t_img *img, int color1, int color2, int status);
void	make_img_translucent(t_img *img, double o);
t_tex	*img_to_tex(t_img *img);
//============================================================================//
//================================ERROR=======================================//
void	*ft_perror(char *error);
//============================================================================//
//===============================PARSING======================================//
t_cub	*map_parsing(char *file);
int		check_char_of_str(t_cub *cub, char **archive, int *count);
int		fill_struct(t_cub *cub, char *line);
int		copy_map(t_cub *cub, char **archive);
int		check_maps(t_cub *cub);
int		copy_archive(int fd, char **archive, int height_archive);
int		count_height_archive(int fd, int *height_archive);
int		init_cub(t_cub	*cub);
int		ft_free_struct(t_cub *cub);
void	free_archive(char **archive);
t_img	*ft_open_img(void *mlx, char *path);
int		separate(t_cub *cub, char **archive);
size_t	ft_strlcpys(char *dst, const char *src, size_t dstsize);
int		identifier_color(char *line, int *color, int *count);
int		check_wall(t_cub *cub, size_t *count_line, size_t *count_int);
//============================================================================//
//===============================MINIMAP======================================//
void	set_zero_minimap(char **minimap, int size);
void	write_minimap(char **minimap, int size);
char	**alloc_minimap(int size);
void	put_chunks_minimap(char **minimap, int i, int j, char c);
void	put_walls_minimap(char **minimap, int x, int y, t_cub *cub);
int		get_color_minimap(char c);
void	put_pixels_minimap(char **minimap, t_cub *cub);
void	draw_minimap(t_cub *cub);
void	free_map(int tam_line, char **map, int fd);
//============================================================================//
//===============================MINIMAP======================================//
void	set_zero_minimap(char **minimap, int size);
void	write_minimap(char **minimap, int size);
char	**alloc_minimap(int size);
void	put_chunks_minimap(char **minimap, int i, int j, char c);
void	put_walls_minimap(char **minimap, int x, int y, t_cub *cub);
int		get_color_minimap(char c);
void	put_pixels_minimap(char **minimap, t_cub *cub);
void	draw_minimap(t_cub *cub);
//============================================================================//
//=================================CUB========================================//
void	start_cub(t_cub *cub);
//============================================================================//
//===============================CONTROLS=====================================//
void	start_controls(t_cub *cub);
//============================================================================//
//=================================MAIN=======================================//
void	start_loop(t_cub *cub);
int		main(int argc, char **argv);

#endif
