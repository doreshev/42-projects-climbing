# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 13:29:01 by doreshev          #+#    #+#              #
#    Updated: 2022/06/22 13:36:11 by doreshev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTDIR = ./libft

CC = cc

AR = ar rcs

RM = rm -f

FLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c \
		ft_printf_d_i_s_c.c \
		ft_printf_p_x.c \
		ft_printf_u.c \

OBJ = ${SRC:.c=.o}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ} libft
	${AR} ${NAME} ${OBJ}

all: ${NAME}

libft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/libft.a .
	@mv libft.a $(NAME)
	
clean:
	${RM} ${OBJ}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all bonus clean fclean re libft