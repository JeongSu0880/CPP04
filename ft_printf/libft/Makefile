# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 14:04:53 by jungslee          #+#    #+#              #
#    Updated: 2023/12/05 15:24:11 by jungslee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRCS = ft_isprint.c ft_strlen.c ft_memmove.c ft_strlcpy.c ft_toupper.c ft_strdup.c ft_strjoin.c ft_itoa.c

OBJS = $(SRCS:%c=%o)
DEP = $(SRCS:%c=%d)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

-include $(DEP)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -MMD -MP -c $(SRCS)

clean :
	rm -rf $(OBJS)
	rm -rf $(DEP)

fclean : clean
	rm -rf $(NAME)

re : fclean all
