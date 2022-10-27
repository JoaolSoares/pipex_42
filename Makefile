# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 02:51:40 by jlucas-s          #+#    #+#              #
#    Updated: 2022/10/27 16:52:52 by jlucas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			pipex

FLAGS =			-Werror -Wall -Wextra

CC =			cc

GREEN =			\033[1;32m
NOCOLOR =		\033[0m

LIBFTPATH =		./lib
LIBFT =			./lib/libft.a

SRCS =			src/mandatory/main.c \
				src/mandatory/fork.c \
				src/mandatory/exec.c \

SRCS_BONUS =	src/bonus/main_bonus.c \
				src/bonus/fork_bonus.c \
				src/bonus/exec_bonus.c \

OBJS =			${SRCS:.c=.o}
OBJS_BONUS =	${SRCS_BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@ make -C ${LIBFTPATH}
	@ $(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@ echo "${GREEN}-=- PIPEX MANDATORY SUCCESSFUL COMPILED -=-${NOCOLOR}"

bonus: ${OBJS_BONUS}
	@ make -C ${LIBFTPATH}
	@ $(CC) $(FLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME)
	@ echo "${GREEN}-=- PIPEX BONUS SUCCESSFUL COMPILED -=-${NOCOLOR}"
	
clean:
	@ rm -f $(OBJS) $(OBJS_BONUS)
	@ make fclean -C ${LIBFTPATH}

rmv:
	@ rm -f $(NAME)

fclean: rmv clean

re: fclean all

refast: rmv all

.PHONY: all bonus clean rmv fclean re refast