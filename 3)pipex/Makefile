# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 13:29:01 by doreshev          #+#    #+#              #
#    Updated: 2022/06/22 13:35:47 by doreshev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFTDIR = ./libft

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

SRC =	pipex.c \
		pipex_utils.c \

OBJ = ${SRC:.c=.o}
INCLUDE = -L./libft -lft

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	@make -C $(LIBFTDIR)
	${CC} ${OBJ} ${INCLUDE} -o ${NAME} 

all: ${NAME}

bonus: all

clean:
	${RM} ${OBJ}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus