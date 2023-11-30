# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 19:28:25 by samusanc          #+#    #+#              #
#    Updated: 2023/11/30 23:31:07 by samusanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address -I ./includes -I ./libft/ -I /usr/local/include 
NAME	= cub3d
CC		= gcc $(CFLAGS)
MLX		= -L /usr/local/lib -lmlx -lm -framework OpenGL -framework AppKit
LIBFT	= -L./libft/ -lft
PPP		= ./mandatory/src/
CONTR_M	= $(PPP)controls/
F_MLX_M	= $(PPP)mlx/
CUB_M	= $(PPP)cub/
MAT_M	= $(PPP)math/
ERR_M	= $(PPP)error/
PAR_M	= $(PPP)parsing/
MAIN_M	= $(PPP)main.c
SRCS	= $(MAIN_M) \
		 \
		$(CONTR_M)close_doors.c		$(CONTR_M)close_x.c			$(CONTR_M)frame.c	\
		$(CONTR_M)hand_loop.c			$(CONTR_M)increase_dpi.c		$(CONTR_M)key_press.c	\
		$(CONTR_M)minimap_zoom.c		$(CONTR_M)mouse_location.c	$(CONTR_M)mouse_press.c \
		$(CONTR_M)mouse_release.c		$(CONTR_M)move.c				$(CONTR_M)move_player.c \
		$(CONTR_M)open_doors.c		$(CONTR_M)put_deltas.c		$(CONTR_M)rotate_view.c \
		$(CONTR_M)start_controls.c	$(CONTR_M)turn_camera.c \
		 \
		$(CUB_M)bresenham/bresenham.c \
		$(CUB_M)bresenham/color_utils.c \
		 \
		$(CUB_M)draw_utils/draw_cross.c \
		$(CUB_M)draw_utils/fill_img_sky_n_ground.c \
		$(CUB_M)draw_utils/get_flat_color.c \
		$(CUB_M)draw_utils/get_opacity.c \
		$(CUB_M)draw_utils/get_pixel_img.c \
		$(CUB_M)draw_utils/make_img_translucent.c \
		$(CUB_M)draw_utils/put_noise.c \
		$(CUB_M)draw_utils/tmp_win.c \
		 \
		$(CUB_M)minimap/draw_direction.c \
		$(CUB_M)minimap/draw_minimark.c \
		$(CUB_M)minimap/minimap.c \
		$(CUB_M)minimap/minimap_utils.c \
		$(CUB_M)minimap/write_map.c \
		 \
		$(CUB_M)raycasting/calculate_cam_plane.c \
		$(CUB_M)raycasting/calculate_ray.c \
		$(CUB_M)raycasting/default_ray.c \
		$(CUB_M)raycasting/draw_ray_map.c \
		$(CUB_M)raycasting/get_next_status.c \
		$(CUB_M)raycasting/make_tmp_ray.c \
		$(CUB_M)raycasting/ray_caster_funtions.c \
		$(CUB_M)raycasting/ray_map_draw_rays.c \
		$(CUB_M)raycasting/ray_map_draw_rays_utils.c \
		$(CUB_M)raycasting/ray_to_point.c \
		 \
		$(CUB_M)sprites/ft_put_sprites.c \
		$(CUB_M)sprites/get_tex.c \
		$(CUB_M)sprites/sprites.c \
		$(CUB_M)sprites/sprites_utils_1.c \
		$(CUB_M)sprites/sprites_utils_2.c \
		$(CUB_M)sprites/sprites_utils_3.c \
		 \
		$(CUB_M)start_cub.c \
		 \
		$(CUB_M)walls/draw_walls.c \
		$(CUB_M)walls/draw_walls_utils_1.c \
		$(CUB_M)walls/draw_walls_utils_2.c \
		$(CUB_M)walls/draw_walls_utils_3.c \
		 \
		$(ERR_M)free_split.c \
		$(ERR_M)ft_perror.c \
		 \
		$(MAT_M)angle_to_radian.c \
		$(MAT_M)closer_int.c \
		$(MAT_M)ft_absf.c \
		$(MAT_M)ft_ds.c \
		$(MAT_M)ft_fit_char.c \
		$(MAT_M)ft_random.c \
		$(MAT_M)get_angle.c \
		$(MAT_M)get_decimal.c \
		$(MAT_M)math.c \
		$(MAT_M)math_utils.c \
		 \
		$(PAR_M)check.c \
		$(PAR_M)check_map.c \
		$(PAR_M)check_walls.c \
		$(PAR_M)copy_map.c \
		$(PAR_M)fill_map.c \
		$(PAR_M)free.c \
		$(PAR_M)get_color.c \
		$(PAR_M)map_parsing.c \
		$(PAR_M)parsing.c \
		$(PAR_M)separate.c \
		$(PAR_M)utils_parsing.c \
		$(PAR_M)open_img.c \
		$(PAR_M)img_to_tex.c \
		$(PAR_M)resize_map.c \
		$(PAR_M)put_sprites.c \
		$(PAR_M)parsing_aux.c \
		$(PAR_M)cub_open_noise.c \
		$(PAR_M)init_img.c \
		$(PAR_M)ft_last_parse.c \

PP		= ./bonus/src/
CONTR_B	= $(PP)controls/
F_BLX_B	= $(PP)mlx/
CUB_B	= $(PP)cub/
MAT_B	= $(PP)math/
ERR_B	= $(PP)error/
PAR_B	= $(PP)parsing/
MAIN_B	= $(PP)main_bonus.c
SRCS_B	= $(MAIN_B) \
		 \
		$(CONTR_B)close_doors_bonus.c		$(CONTR_B)close_x_bonus.c			$(CONTR_B)frame_bonus.c \
		$(CONTR_B)hand_loop_bonus.c		$(CONTR_B)increase_dpi_bonus.c	$(CONTR_B)key_press_bonus.c \
		$(CONTR_B)minimap_zoom_bonus.c	$(CONTR_B)mouse_location_bonus.c	$(CONTR_B)mouse_press_bonus.c \
		$(CONTR_B)mouse_release_bonus.c	$(CONTR_B)move_bonus.c			$(CONTR_B)move_player_bonus.c \
		$(CONTR_B)open_doors_bonus.c		$(CONTR_B)put_deltas_bonus.c		$(CONTR_B)rotate_view_bonus.c \
		$(CONTR_B)start_controls_bonus.c	$(CONTR_B)turn_camera_bonus.c \
		 \
		$(CUB_B)bresenham/bresenham_bonus.c \
		$(CUB_B)bresenham/color_utils_bonus.c \
		 \
		$(CUB_B)draw_utils/draw_cross_bonus.c \
		$(CUB_B)draw_utils/fill_img_sky_n_ground_bonus.c \
		$(CUB_B)draw_utils/get_flat_color_bonus.c \
		$(CUB_B)draw_utils/get_opacity_bonus.c \
		$(CUB_B)draw_utils/get_pixel_img_bonus.c \
		$(CUB_B)draw_utils/make_img_translucent_bonus.c \
		$(CUB_B)draw_utils/put_noise_bonus.c \
		$(CUB_B)draw_utils/tmp_win_bonus.c \
		 \
		$(CUB_B)minimap/draw_direction_bonus.c \
		$(CUB_B)minimap/draw_minimark_bonus.c \
		$(CUB_B)minimap/minimap_bonus.c \
		$(CUB_B)minimap/minimap_utils_bonus.c \
		$(CUB_B)minimap/write_map_bonus.c \
		 \
		$(CUB_B)raycasting/calculate_cam_plane_bonus.c \
		$(CUB_B)raycasting/calculate_ray_bonus.c \
		$(CUB_B)raycasting/default_ray_bonus.c \
		$(CUB_B)raycasting/draw_ray_map_bonus.c \
		$(CUB_B)raycasting/get_next_status_bonus.c \
		$(CUB_B)raycasting/make_tmp_ray_bonus.c \
		$(CUB_B)raycasting/ray_caster_funtions_bonus.c \
		$(CUB_B)raycasting/ray_map_draw_rays_bonus.c \
		$(CUB_B)raycasting/ray_map_draw_rays_utils_bonus.c \
		$(CUB_B)raycasting/ray_to_point_bonus.c \
		 \
		$(CUB_B)sprites/ft_put_sprites_bonus.c \
		$(CUB_B)sprites/get_tex_bonus.c \
		$(CUB_B)sprites/sprites_bonus.c \
		$(CUB_B)sprites/sprites_utils_1_bonus.c \
		$(CUB_B)sprites/sprites_utils_2_bonus.c \
		$(CUB_B)sprites/sprites_utils_3_bonus.c \
		 \
		$(CUB_B)start_cub_bonus.c \
		 \
		$(CUB_B)walls/draw_walls_bonus.c \
		$(CUB_B)walls/draw_walls_utils_1_bonus.c \
		$(CUB_B)walls/draw_walls_utils_2_bonus.c \
		$(CUB_B)walls/draw_walls_utils_3_bonus.c \
		 \
		$(ERR_B)free_split_bonus.c \
		$(ERR_B)ft_perror_bonus.c \
		 \
		$(MAT_B)angle_to_radian_bonus.c \
		$(MAT_B)closer_int_bonus.c \
		$(MAT_B)ft_absf_bonus.c \
		$(MAT_B)ft_ds_bonus.c \
		$(MAT_B)ft_fit_char_bonus.c \
		$(MAT_B)ft_random_bonus.c \
		$(MAT_B)get_angle_bonus.c \
		$(MAT_B)get_decimal_bonus.c \
		$(MAT_B)math_bonus.c \
		$(MAT_B)math_utils_bonus.c \
		 \
		$(PAR_B)check_bonus.c \
		$(PAR_B)check_map_bonus.c \
		$(PAR_B)check_walls_bonus.c \
		$(PAR_B)copy_map_bonus.c \
		$(PAR_B)fill_map_bonus.c \
		$(PAR_B)free_bonus.c \
		$(PAR_B)get_color_bonus.c \
		$(PAR_B)map_parsing_bonus.c \
		$(PAR_B)parsing_bonus.c \
		$(PAR_B)separate_bonus.c \
		$(PAR_B)utils_parsing_bonus.c \
		$(PAR_B)open_img_bonus.c \
		$(PAR_B)img_to_tex_bonus.c \
		$(PAR_B)resize_map_bonus.c \
		$(PAR_B)put_sprites_bonus.c \
		$(PAR_B)parsing_aux_bonus.c \
		$(PAR_B)cub_open_noise_bonus.c \
		$(PAR_B)init_img_bonus.c \
		$(PAR_B)ft_last_parse_bonus.c \

O_DIR	= ./objects/
B_O_DIR	= ./bonus_objects/
OBJS	= $(addprefix $(O_DIR)/, $(SRCS:.c=.o))
B_OBJS	= $(addprefix $(B_O_DIR)/, $(SRCS_B:.c=.o))

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $(O_DIR)/$(<:.c=.o)

$(B_O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -D BONUS=1 -c $< -o $(B_O_DIR)/$(<:.c=.o)

all: .mandatory
	@echo "mandatory done!!!"

bonus: .bonus
	@echo "Bonus done!!!"

.bonus: $(B_OBJS) includes/cub.h
	@echo "cleaning mandatory..."
	@rm -rf .mandatory
	@rm -f $(NAME)
	@rm -f $(OBJS)
	@rm -rf $(O_DIR)
	@echo "compiling libft..."
	@make -sC ./libft/
	@echo "compiling objects..."
	@$(CC) $(B_OBJS) $(MLX) $(LIBFT) $(GNL) -o $(NAME)_bonus
	@touch .bonus

.mandatory: $(OBJS) includes/cub.h
	@echo "cleaning bonus..."
	@rm -rf .bonus
	@rm -f $(NAME)_bonus
	@rm -f $(B_OBJS)
	@rm -rf $(B_O_DIR)
	@echo "compiling libft..."
	@make -sC ./libft/
	@echo "compiling objects..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(GNL) -o $(NAME)
	@touch .mandatory

re: fclean all

fclean: clean
	@echo "cleaning binaries..."
	@make -sC ./libft/ fclean
	@rm -f $(NAME)
	@rm -f $(NAME)_bonus
	@rm -rf .bonus
	@rm -rf .mandatory
	@rm -rf .clean

clean: .clean
	@echo "objects removed!"

.clean:
	@echo "cleaning objects..."
	@make -sC ./libft/ clean
	@rm -f $(OBJS)
	@rm -f $(B_OBJS)
	@rm -rf $(O_DIR)
	@rm -rf $(B_O_DIR)
	@touch .clean

.PHONY: all bonus clean fclean re
