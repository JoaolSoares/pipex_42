# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 02:51:40 by jlucas-s          #+#    #+#              #
#    Updated: 2022/10/25 14:28:45 by jlucas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAGS = -Werror -Wall -Wextra

GREEN				= \033[1;32m
NOCOLOR				= \033[0m

LIBFTPATH = ./lib
LIBFT = ./lib/libft.a

MSRCS =	src/mandatory/main.c \
		src/mandatory/fork.c \
		src/mandatory/exec.c \

BSRCS = src/bonus/main_bonus.c \
		src/bonus/fork_bonus.c \
		src/bonus/exec_bonus.c \

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFTPATH}
	cc $(MSRCS) $(LIBFT) $(FLAGS) -o $(NAME)
	@ echo "${GREEN}-=- PIPEX MANDATORY SUCCESSFUL COMPILED -=-${NOCOLOR}"

bonus: ${OBJS}
	make -C ${LIBFTPATH}
	cc $(BSRCS) $(LIBFT) $(FLAGS) -o $(NAME)
	@ echo "${GREEN}-=- PIPEX BONUS SUCCESSFUL COMPILED -=-${NOCOLOR}"
	
clean:
	make fclean -C ${LIBFTPATH}

rmv:
	rm -f $(NAME)

fclean: rmv clean

re: fclean all

refast: rmv all

.PHONY: all clean rmv fclean re refast