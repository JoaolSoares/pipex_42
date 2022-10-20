# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 02:51:40 by jlucas-s          #+#    #+#              #
#    Updated: 2022/10/21 01:47:36 by jlucas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAGS = -Werror -Wall -Wextra

GREEN				= \033[1;32m
NOCOLOR				= \033[0m

LIBFTPATH = ./lib
LIBFT = ./lib/libft.a

SRCS =	src/main.c \
		src/exec.c \

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFTPATH}
	cc $(SRCS) $(LIBFT) $(FLAGS) -o $(NAME)
	@ echo "${GREEN}-=- PIPEX SUCCESSFUL COMPILED -=-${NOCOLOR}"
	
clean:
	make fclean -C ${LIBFTPATH}

rmv:
	rm -f $(NAME)

fclean: rmv clean

re: fclean all

refast: rmv all

.PHONY: all clean rmv fclean re refast