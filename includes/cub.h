/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:59:01 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 12:48:17 by samusanc         ###   ########.fr       */
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
# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_tex{
	int		**tex;
	size_t	size;
}				t_tex;

typedef	struct s_spr{
	size_t	x;
	size_t	y;
	int		blink;
	int		frame;
	size_t	next_frame;
	size_t	next_blink;
}				t_spr;

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
 *		10 ghost
 */
typedef struct s_cub{
	//=========================//
	//        MAP_UTILS        //
	size_t	**map;
	size_t	map_width;
	size_t	map_height;
	float	**screen;
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
	//=========================//
	//          NINA           //
	t_img	*nina_cam[3][5];
	t_img	*nina_ncam[5];
	t_tex	*t_nina_cam[3][5];
	t_tex	*t_nina_ncam[5];
	t_spr	**sprites;
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

//============================================================================//
//================================MATH========================================//
float	ft_random(float n, float min, float max);
void	free_split(char **input);
double	ft_ds(double xi, double xf, double yi, double yf);
double	angle_to_radian(double angle);
double	get_angle(double angle);
double	get_decimal(double x);
double	ft_abs2(double x);
float	ft_fit_char(float n, float min, float max);
float	ft_random(float n, float min, float max);
double	closer_int(double n);
void	put_deltas(t_cub *cub);
//============================================================================//
//=================================MLX========================================//
int		get_pixel_img(t_img *img, int x, int y);
int		cub_open_utils(t_cub *cub);
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	ft_fill_img(t_img *img, int color);
t_img	*ft_init_img(void *mlx, int width, int height);
void	draw_square(t_img *img, t_square sq);
void	fill_img_sky_n_ground(t_img *img, int color1, int color2, int status);
void	make_img_translucent(t_img *img, double o);
t_tex	*img_to_tex(t_img *img);
double	get_opacity(int color);
int		get_flat_color(int color);
void	make_img_translucent(t_img *img, double o);
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
void	fill_img_sky_n_ground(t_img *img, int color1, int color2, int status);
void	free_split(char **input);
void	write_map(t_cub *cub);
void	draw_direction(t_cub *cub);
void	draw_minimark(t_cub *cub);
void	draw_walls(t_cub *cub, t_ray ray, size_t actual_ray, size_t total_rays, int side, int win);
t_p		default_ray(t_cub *cub);
t_p		calculate_cam_plane(t_ray ray, t_cub *cub);
t_ray	calculate_ray(t_ray tmp_ray, t_cub *cub, int color);
t_ray	make_tmp_ray(float x, float y, float angle, t_cub *cub);
t_p		ray_to_point(t_ray ray);
int		get_next_status(t_cub *cub, float ray_a, float *ds, int m, float last_distance);
void	ray_map_draw_rays(t_cub *cub);
void	draw_ray_map(t_cub *cub);
void	draw_cross(t_cub *cub);
t_win	tmp_win(void *mlx, void *win, t_img *result);
void	put_noise(t_cub *cub);
void	ray_caster(t_cub *cub);
void	sprites(t_cub *cub, float sx, float sy, t_tex *tex);
t_tex	*get_tex(t_cub *cub, t_spr *tmp);
void	ft_put_sprites(t_cub *cub);
void	start_cub(t_cub *cub);
//============================================================================//
//===============================CONTROLS=====================================//
void	close_x(void *param);
void	open_doors(t_cub *cub);
void	close_doors(t_cub *cub);
void	minimap_zoom(t_cub *cub, int key);
void	hand_loop(t_cub *cub);
void	move_left(t_cub *cub, float *starty, float *startx);
void	move_right(t_cub *cub, float *starty, float *startx);
void	move_up(t_cub *cub, float *starty, float *startx);
void	move_down(t_cub *cub, float *starty, float *startx);
void	put_deltas(t_cub *cub);
void	rotate_view_left(t_cub *cub);
void	rotate_view_rigth(t_cub *cub);
void	move_player(int key, t_cub *cub);
void	increase_dpi(t_cub *cub, int key);
void	turn_camera(t_cub *cub);
void	key_press(int key, void *param);
void	frame(void *param);
void	mouse_location(int x, int y, void *param);
void	mouse_press(int key, int x, int y, void *param);
void	mouse_release(int key, int x, int y, void *param);
void	start_controls(t_cub *cub);
//============================================================================//
//=================================MAIN=======================================//
void	start_loop(t_cub *cub);
int		main(int argc, char **argv);

#endif
