# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 19:28:25 by samusanc          #+#    #+#              #
#    Updated: 2023/10/31 13:18:12 by samusanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address -I ./includes -I ./libft/ -I /usr/local/include 
CC		= gcc $(CFLAGS)
MLX		= -L /usr/local/lib -lmlx -lm -framework OpenGL -framework AppKit
LIBFT	= -L./libft/ -lft
CONTR	= src/controls/
F_MLX	= src/mlx/
CUB		= src/cub/
ERR		= src/error/
PAR		= src/parsing/
MAIN	= src/main.c
SRCS	= $(MAIN) \
		  $(PAR)map_parsing.c \
		  $(CONTR)start_controls.c \
		  $(CUB)start_cub.c \
		  $(CUB)/minimap/minimap.c \
		  $(CUB)/minimap/minimap_utils.c \
		  $(ERR)ft_perror.c \

O_DIR	= ./objects/
OBJS	= $(addprefix $(O_DIR)/, $(SRCS:.c=.o))

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $(O_DIR)/$(<:.c=.o)

all: $(NAME) includes/cub.h

$(NAME): $(OBJS)
	@make -sC ./libft/
	@$(CC) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)

re: fclean all

fclean: clean
	@make -sC ./libft/ fclean
	@rm -f $(NAME)

clean:
	@make -sC ./libft/ clean
	@rm -f $(OBJS)
	@rm -rf $(O_DIR)

.PHONY: all
