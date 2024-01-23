# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungslee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 13:16:33 by jungslee          #+#    #+#              #
#    Updated: 2023/09/14 16:48:00 by jungslee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
TARGET = libft.a
SRCS = ./srcs/ft_putchar.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c ./srcs/ft_putstr.c
OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar rc $@ $^

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c -o $(OBJS) $(SRCS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(TARGET)

re : fclean all
