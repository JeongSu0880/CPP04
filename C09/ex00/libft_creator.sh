# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungslee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 20:46:36 by jungslee          #+#    #+#              #
#    Updated: 2023/09/14 13:15:41 by jungslee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

gcc -g -Wall -Werror -Wextra -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
ar rscv libft.a *.o
