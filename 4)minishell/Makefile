# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 13:29:01 by doreshev          #+#    #+#              #
#    Updated: 2022/07/27 14:03:20 by doreshev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFTDIR = ./libft

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

SRC =	minishell.c \
		ms_utils.c \
		init/init.c \
		init/init_utils.c \
		init/tokens.c \
		init/tokens2.c \
		lexer/ft_lexer.c \
		lexer/ft_lexer_utils.c \
		exec/ft_exec.c \
		exec/ft_exec_cmd.c \
		exec/ft_exec_utils.c \
		exec/ft_exec_redir.c \
		exec/ft_heredoc.c \
		sig/signals.c \
		build-in/build-in.c \
		build-in/echo_cd.c \
		build-in/pwd_exit_env.c \
		build-in/export.c \
		build-in/unset.c \

OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
INCLIBFT = -L./libft -lft
INCREADL = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib
INCREADH = -I /Users/$(USER)/.brew/opt/readline/include

.c.o:
	${CC} ${FLAGS} ${INCREADH} -MMD -MP -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	@make -C $(LIBFTDIR)
	${CC} ${OBJ} ${INCLIBFT} ${INCREADL} -o ${NAME}
	
all: ${NAME}

bonus: all

clean:
	${RM} ${OBJ} ${DEP}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEP)