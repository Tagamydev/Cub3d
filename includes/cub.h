/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:59:01 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/31 21:30:32 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <mlx.h>
# include <math.h>
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
# define SPEED 0.8
# define PI 3.1415926535

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
 */

typedef struct s_cub{
	//=========================//
	//        MAP_UTILS        //
	size_t	**map;
	size_t	map_width;
	size_t	map_height;
	t_img	*no_texture;
	t_img	*so_texture;
	t_img	*ea_texture;
	t_img	*we_texture;
	int		color_ground;
	int		color_sky;
	//=========================//
	//        MLX_UTILS        //
	void	*mlx;
	void	*win;
	t_img	*game;
	t_img	*minimap;
	//=========================//
	//          PLAYER         //
	float	player_px;
	float	player_py;
	float	player_dx;
	float	player_dy;
	float	player_a;
	//=========================//
	//          MINIMAP        //
	int		minimap_zoom;
}				t_cub;

void	free_split(char **input);
//============================================================================//
//=================================MLX========================================//
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	ft_fill_img(t_img *img, int color);
t_img	*ft_init_img(void *mlx, int width, int height);
void	draw_square(t_img *img, t_square sq);
void	fill_img_sky_n_ground(t_img *img, int color1, int color2);
//============================================================================//
//================================ERROR=======================================//
void	*ft_perror(char *error);
//============================================================================//
//===============================PARSING======================================//
t_cub	*map_parsing(char *file);
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
