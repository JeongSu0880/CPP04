# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 21:35:39 by jungslee          #+#    #+#              #
#    Updated: 2023/12/04 15:30:46 by jungslee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS = ft_printf.c type.c ft_itoa_hex.c handle_type_1.c handle_type_2.c ft_itoa_u.c
MAKE = make
SUB_LIB = libft.a
SUB_DIR = ./libft
OBJS = $(SRCS:%c=%o)

all : $(NAME)

$(NAME) : $(OBJS) $(SUB_DIR)/$(SUB_LIB)
	cp $(SUB_DIR)/$(SUB_LIB) $(NAME)
	ar rcs $@ $^

$(SUB_DIR)/$(SUB_LIB) :
	$(MAKE) -C $(SUB_DIR)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean :
	rm -rf $(OBJS)
	rm -rf $(OBJS_B)
	$(MAKE) -C ./libft clean

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
