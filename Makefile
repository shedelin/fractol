# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shedelin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/21 15:44:45 by shedelin          #+#    #+#              #
#    Updated: 2015/04/21 15:44:53 by shedelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CUR		= fractol/

CC		= gcc

HEADER	= srcs/libft/includes/

CFLAGS	= -Wall -Wextra -Werror

SRCS = main.c \
	   mandelbrot.c \
	   julia.c \
	   tools.c \
	   mouse.c \
	   mlx_f.c \
	   custom.c

OBJS = OBJS/


OBJ = $(SRCS:.c=.o)

OBJ := $(addprefix $(OBJS), $(OBJ))

SRCS_F = srcs/

SRCS := $(addprefix $(SRCS_F), $(SRCS))


all : mlx $(NAME)

$(NAME) : $(OBJ) includes/fractol.h
	@make -C srcs/libft/
	@$(CC) -o $(NAME) $(OBJ) -L srcs/libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

$(OBJS)%.o : $(SRCS_F)%.c
	@mkdir -p $(OBJS)
	@$(CC) $(CFLAGS) -c $< -I $(HEADER) -I includes/ -o $@

mlx :
	@make -C minilibx_macos/

clean :
	@make -C minilibx_macos/ clean
	@make -C srcs/libft/ clean
	@rm -rf $(OBJS)

fclean : clean
	@make -C srcs/libft/ fclean
	@echo ""
	@rm -rf $(NAME)

re : fclean all

.PHONY :
	all clean re mlx
