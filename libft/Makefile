# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 13:35:22 by samusanc          #+#    #+#              #
#    Updated: 2023/07/01 15:07:50 by samusanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OMAIN	=	../main/main.c
MAIN	= 	main.c
HFILES	= 	libft.h
NAME 	= 	libft.a

CC		= 	gcc
OUT		= 	adeu
AR		=	ar rcs 

OF		=	*.c Makefile libft.h

GA		=	git add
GC		=	git commit -m "subiendo prueba"

CFLAGS	= 	-Wextra -Werror -Wall
SRC		= \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			\
			ft_atoi.c \
			ft_bzero.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_substr.c \
			ft_split.c \
			ft_itoa.c \
			\
			ft_memset.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			\
			ft_strlen.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_striteri.c \
			\
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			\
			GNL/get_next_line.c \
			GNL/get_next_line_utils.c \
			\
			printf/src/ft_format_char.c \
			printf/src/ft_format_hex.c \
			printf/src/ft_format_numbers.c \
			printf/src/ft_format_string.c \
			printf/ft_printf.c \

OBJ		= 	$(SRC:.c=.o)

# COLORS

BLACK	=	\033[0;30m
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m
CYAN	=	\033[0;36m
RESET	=	\033[0m

#ALL
all		: 	$(NAME)

$(MAIN)	:	$(OMAIN)
			cp $(OMAIN) ./

MAINO	=	$(MAIN:.c=.o)
L		=	main.o -L. -lft

$(NAME)	: 	$(OBJ)
			$(AR) $@ $^
$(OUT)	: 	$(NAME) $(MAINO)
			@$(CC) $(CFLAGS) -o $(OUT) $(L)

#CLEAN
clean	:
			@rm -f $(OBJ)
			@echo "$(MAGENTA)===> objects have been removed$(MAGENTA)"
fclean	:
			@rm -f $(OBJ) $(NAME) $(OUT) main.o $(MAIN)
			@echo "$(MAGENTA)===> all clean$(MAGENTA)"

#GIT
add		:
			@$(GA) $(OF)
commit	:
			@$(GC)

re		:	fclean all

.PHONY:		all clean fclean re bonus
