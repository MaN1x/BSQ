# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjoss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/21 19:53:50 by mjoss             #+#    #+#              #
#    Updated: 2019/08/22 02:41:29 by mjoss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCS = srcs/main.c srcs/solve.c srcs/functions.c srcs/ft_atoi.c srcs/check.c srcs/check_valid_to_head.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRCS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
