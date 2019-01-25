# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/16 16:23:43 by pdoherty          #+#    #+#              #
#    Updated: 2018/12/02 21:36:42 by pdoherty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = *.c

OUT = $(SRCS:%.c=%.o)

INCLUDES = libft.h

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -c $(SRCS) -I $(INCLUDES)
	@ar rcs $(NAME) $(OUT)
	@ranlib $(NAME)
	
clean:
	@rm -f $(OUT)

fclean:
	@rm -f $(OUT)
	@rm -f $(NAME)

re: fclean $(NAME)
