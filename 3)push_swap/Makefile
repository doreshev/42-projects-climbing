# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 13:29:01 by doreshev          #+#    #+#              #
#    Updated: 2022/06/22 13:21:10 by doreshev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

LIBFTDIR = ./libft

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

SRC =	push_swap.c \
		ft_cases_a.c \
		ft_cases_b.c \
		ft_sort_utils.c \
		ft_sort.c \
		print_commands.c \

PROC =	ft_process.c \
		ft_lstutils.c \
		ft_commands_a.c \
		ft_commands_b.c \
		ft_commands_ab.c \
		ft_chkerr.c \

BNS =	checker.c \

OBJ = ${SRC:.c=.o}
PROCOBJ = ${PROC:.c=.o}
BNSOBJ = ${BNS:.c=.o}
INCLUDE = -L./libft -lft

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ} ${PROCOBJ}
	@make -C $(LIBFTDIR)
	${CC} ${OBJ} ${PROCOBJ} ${INCLUDE} -o ${NAME} 

${BONUS}: ${PROCOBJ} ${BNSOBJ}
	@make -C $(LIBFTDIR)
	${CC} ${BNSOBJ} ${PROCOBJ} ${INCLUDE} -o ${BONUS}

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJ} ${BNSOBJ} ${PROCOBJ}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} ${BONUS} ${PROCOBJ}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus