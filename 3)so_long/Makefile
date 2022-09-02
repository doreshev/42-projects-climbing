# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 13:29:01 by doreshev          #+#    #+#              #
#    Updated: 2022/06/22 13:37:06 by doreshev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS = so_long_bonus

LIBFTDIR = ./libft

MLXDIR = ./mlx

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

SRC =	so_long.c \
		ft_map_process.c \
		ft_game.c \
		so_long_utils.c \
		ft_key_hook.c \

BNS =	bonus/bonus_so_long.c \
		bonus/bonus_map_process.c \
		bonus/bonus_game.c \
		bonus/bonus_so_long_utils.c \
		bonus/bonus_key_hook.c \
		bonus/bonus_enemy.c \

OBJ = ${SRC:.c=.o}
BOBJ = ${BNS:.c=.o}
INLIBFT = -L./libft -lft
INMLX = -L./mlx -lmlx

.c.o:
	${CC} ${FLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJ}
	@make -C $(LIBFTDIR)
	@make -C $(MLXDIR)
	${CC} ${OBJ} ${INLIBFT} ${INMLX} -framework OpenGL -framework AppKit -o ${NAME} 


bonus: ${BOBJ}
	@make -C $(LIBFTDIR)
	@make -C $(MLXDIR)
	${CC} ${BOBJ} ${INLIBFT} ${INMLX} -framework OpenGL -framework AppKit -o ${BONUS} 

all: ${NAME}

clean:
	${RM} ${OBJ} ${BOBJ}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd $(MLXDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus