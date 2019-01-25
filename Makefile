# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 20:41:43 by pdoherty          #+#    #+#              #
#    Updated: 2018/12/03 10:45:50 by pdoherty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIB = libftprintf.a

SRCS = *.c

OBJ = $(SRCS:%.c=%.o)

INCLUDES = ft_ls.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C libftprintf
	@cp libftprintf/libftprintf.a libftprintf.a
	@gcc $(FLAGS) -c $(SRCS)
	@gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	@make -C libftprintf clean
	@rm -f $(OBJ)
	@rm -f $(LIB)

fclean:
	@make -C libftprintf fclean
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@rm -f $(LIB)

re: fclean all
