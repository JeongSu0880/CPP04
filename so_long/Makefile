# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 17:15:27 by jungslee          #+#    #+#              #
#    Updated: 2024/03/28 21:52:44 by jungslee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = so_long
SRCS = 	map_validity.c \
		map_init.c \
		main.c \
		exit_game.c \
		enemy.c \
		utils.c \
		print.c \
		map_validity_2.c \
		stack.c \
		player_move.c
OBJS = $(SRCS:%c=%o)

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(SRCS) -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit -g -o so_long

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all