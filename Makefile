# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 19:28:25 by samusanc          #+#    #+#              #
#    Updated: 2023/11/29 13:59:33 by samusanc         ###   ########.fr        #
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
		  $(PAR)utils_parsing.c \
		  $(PAR)free.c \
		  $(PAR)fill_map.c \
		  $(PAR)copy_map.c \
		  $(PAR)check.c \
		  $(CONTR)start_controls.c \
		  $(MAT)math.c \
		  $(CUB)start_cub.c \
		  $(CUB)/minimap/minimap.c \
		  $(CUB)/minimap/minimap_utils.c \
		  $(CUB)/bresenham/bresenham.c \
		  $(ERR)ft_perror.c \
		  $(PAR)map_parsing.c \
		  $(PAR)parsing.c \
		  $(PAR)check_map.c \
		  $(PAR)check_walls.c \
		  $(PAR)get_color.c \
		  $(PAR)separate.c \


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
