# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 19:28:25 by samusanc          #+#    #+#              #
#    Updated: 2023/11/30 13:33:34 by samusanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.mandatory:	CFLAGS	= -Wall -Wextra -Werror -g3 -D BONUS=1 -fsanitize=address -I ./includes -I ./libft/ -I /usr/local/include 
.bonus:		CFLAGS	= -Wall -Wextra -Werror -g3 -D BONUS=1 -fsanitize=address -I ./includes -I ./libft/ -I /usr/local/include 
NAME	= cub3d
CC		= gcc $(CFLAGS)
MLX		= -L /usr/local/lib -lmlx -lm -framework OpenGL -framework AppKit
LIBFT	= -L./libft/ -lft
CONTR	= src/controls/
F_MLX	= src/mlx/
CUB		= src/cub/
MAT		= src/math/
ERR		= src/error/
PAR		= src/parsing/
MAIN	= src/main.c
SRCS	= $(MAIN) \
		 \
		./src/controls/close_doors.c \
		./src/controls/close_x.c \
		./src/controls/frame.c \
		./src/controls/hand_loop.c \
		./src/controls/increase_dpi.c \
		./src/controls/key_press.c \
		./src/controls/minimap_zoom.c \
		./src/controls/mouse_location.c \
		./src/controls/mouse_press.c \
		./src/controls/mouse_release.c \
		./src/controls/move.c \
		./src/controls/move_player.c \
		./src/controls/open_doors.c \
		./src/controls/put_deltas.c \
		./src/controls/rotate_view.c \
		./src/controls/start_controls.c \
		./src/controls/turn_camera.c \
		 \
		./src/cub/bresenham/bresenham.c \
		./src/cub/bresenham/color_utils.c \
		 \
		./src/cub/draw_utils/draw_cross.c \
		./src/cub/draw_utils/fill_img_sky_n_ground.c \
		./src/cub/draw_utils/get_flat_color.c \
		./src/cub/draw_utils/get_opacity.c \
		./src/cub/draw_utils/get_pixel_img.c \
		./src/cub/draw_utils/make_img_translucent.c \
		./src/cub/draw_utils/put_noise.c \
		./src/cub/draw_utils/tmp_win.c \
		 \
		./src/cub/minimap/draw_direction.c \
		./src/cub/minimap/draw_minimark.c \
		./src/cub/minimap/minimap.c \
		./src/cub/minimap/minimap_utils.c \
		./src/cub/minimap/write_map.c \
		 \
		./src/cub/raycasting/calculate_cam_plane.c \
		./src/cub/raycasting/calculate_ray.c \
		./src/cub/raycasting/default_ray.c \
		./src/cub/raycasting/draw_ray_map.c \
		./src/cub/raycasting/get_next_status.c \
		./src/cub/raycasting/make_tmp_ray.c \
		./src/cub/raycasting/ray_caster_funtions.c \
		./src/cub/raycasting/ray_map_draw_rays.c \
		./src/cub/raycasting/ray_to_point.c \
		 \
		./src/cub/sprites/ft_put_sprites.c \
		./src/cub/sprites/get_tex.c \
		./src/cub/sprites/sprites.c \
		 \
		./src/cub/start_cub.c \
		 \
		./src/cub/walls/draw_walls.c \
		 \
		./src/error/free_split.c \
		./src/error/ft_perror.c \
		 \
		./src/math/angle_to_radian.c \
		./src/math/closer_int.c \
		./src/math/ft_absf.c \
		./src/math/ft_ds.c \
		./src/math/ft_fit_char.c \
		./src/math/ft_random.c \
		./src/math/get_angle.c \
		./src/math/get_decimal.c \
		./src/math/math.c \
		./src/math/math_utils.c \
		 \
		./src/parsing/check.c \
		./src/parsing/check_map.c \
		./src/parsing/check_walls.c \
		./src/parsing/copy_map.c \
		./src/parsing/fill_map.c \
		./src/parsing/free.c \
		./src/parsing/get_color.c \
		./src/parsing/map_parsing.c \
		./src/parsing/parsing.c \
		./src/parsing/separate.c \
		./src/parsing/utils_parsing.c \


O_DIR	= ./objects/
OBJS	= $(addprefix $(O_DIR)/, $(SRCS:.c=.o))

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $(O_DIR)/$(<:.c=.o)

all: .mandatory
	@echo "mandatory done!!!"

bonus: .bonus
	@echo "Bonus done!!!"

.bonus: clean $(OBJS) includes/cub.h
	@echo "cleaning mandatory..."
	@rm -rf .mandatory
	@echo "compiling libft..."
	@make -sC ./libft/
	@echo "compiling objects..."
	@$(CC) $(OBJS) $(MLX) $(LIBFT) $(GNL) -o $(NAME)
	@touch .bonus

.mandatory: $(OBJS) includes/cub.h
	@echo "compiling libft..."
	@make -sC ./libft/
	@echo "compiling objects..."
	@$(CC) $(OBJS) $(MLX) $(LIBFT) $(GNL) -o $(NAME)
	@touch .mandatory

re: fclean all

fclean: clean
	@echo "cleaning binaries..."
	@make -sC ./libft/ fclean
	@rm -f $(NAME)
	@rm -rf .bonus
	@rm -rf .mandatory
	@rm -rf .clean

clean: .clean
	@echo "objects removed!"

.clean:
	@echo "cleaning objects..."
	@make -sC ./libft/ clean
	@rm -f $(OBJS)
	@rm -rf $(O_DIR)
	@touch .clean

.PHONY: all bonus clean fclean re
