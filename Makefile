# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsuonper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/02 14:48:04 by jsuonper          #+#    #+#              #
#    Updated: 2020/01/02 15:25:52 by jsuonper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS_DIR = src/
SRCS_LIST = main.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

INCLUDES_DIR = includes
INCLUDES_LIST = fdf.h
INCLUDES = $(addprefix $(INCLUDES_DIR), $(INCLUDES_LIST))

OBJ = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Werror -Wall -Wextra


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
