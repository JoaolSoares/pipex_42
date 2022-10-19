# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 02:51:40 by jlucas-s          #+#    #+#              #
#    Updated: 2022/10/19 18:58:25 by jlucas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAGS = -Werror -Wall -Wextra

GREEN				= \033[1;32m
NOCOLOR				= \033[0m

LIBFTPATH = ./lib
LIBFT = ./lib/libft.a

SRCS =	src/main.c \
		src/validations.c \
		src/opens.c \
		src/allocs.c \

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