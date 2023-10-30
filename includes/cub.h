/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:59:01 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/30 12:18:26 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <libft.h>
# include <ft_perror.h>
# define WIDTH 640
# define HEIGHT 480

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
}				t_cub;

//============================================================================//
//=================================MLX========================================//
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	ft_fill_img(t_img *img, int color);
t_img	*ft_init_img(void *mlx, int width, int height);
//============================================================================//
//================================ERROR=======================================//
void	*ft_perror(char *error);
//============================================================================//
//===============================PARSING======================================//
t_cub	*map_parsing(char *file);
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
