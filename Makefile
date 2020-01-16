# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/02 14:48:04 by jsuonper          #+#    #+#              #
#    Updated: 2020/01/16 11:46:22 by jsuonper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

#SOURCES
SRCS_DIR = src/
SRCS_LIST = main.c\
			create_mlx_struct.c\
			create_coords.c\
			bresenham.c\
			make_square.c\
			make_cube.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

#INCLUDES
INCLUDES_DIR = includes/
INCLUDES_LIST = fdf.h
INCLUDES = $(addprefix $(INCLUDES_DIR), $(INCLUDES_LIST))
LIBFT = libft/libft.a

#COMPILATION
OBJ = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Werror -Wall -Wextra


all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lmlx -framework OpenGL -framework AppKit

clean:
	make clean -C libft 
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft 
	rm -f $(NAME)

re: fclean all
