# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 13:29:01 by doreshev          #+#    #+#              #
#    Updated: 2022/09/26 12:45:20 by doreshev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

CC = c++

RM = rm -f

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp \
		Identify.cpp \

OBJ = ${SRC:.cpp=.o}
DEP = ${SRC:.cpp=.d}

.cpp.o:
	${CC} ${FLAGS} -MMD -MP -c $< -o ${<:.cpp=.o}

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJ} ${DEP}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)