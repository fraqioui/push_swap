# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 07:54:41 by fraqioui          #+#    #+#              #
#    Updated: 2022/12/24 16:24:15 by fraqioui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
HEADER = push_swap.h

FILES =	algo_five \
		algo_three \
		calc_moves_needed \
		checking \
		helpers \
		lis_algo \
		list_creation \
		lis \
		main \
		minmax \
		moves_neg \
		moves_posi \
		operations1 \
		operations2 \
		operations3 \
		push_swap_utils1 \
		push_swap_utils2

BFILES = bonus \
		push_swap_utils_bonus \
		checking \
		list_creation \
		operations1 \
		operations2 \
		operations3 \
		push_swap_utils1 \
		push_swap_utils2 \
		get_next_line \
		get_next_line_utils

OBJ = ${FILES:=.o}
BOBJ = ${BFILES:=.o}

.PHONY: all bonus clean fclean re

all: ${NAME}
new = checker

${NAME}: ${OBJ} ${HEADER}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

bonus: ${BOBJ} ${HEADER}
	${CC} ${FLAGS} ${BOBJ} -o ${new}

clean:
	${RM} ${OBJ} ${BOBJ}
fclean: clean
	${RM} ${NAME} ${new}
re: fclean all
