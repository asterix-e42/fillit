# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcollett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 22:20:44 by gcollett          #+#    #+#              #
#    Updated: 2016/12/05 01:22:28 by gcollett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

SRC		=	display.c	\
			ft_square.c	\
			ft_dlist.c	\
			ft_alloc.c	

CFLAGS	=	-Wall -Wextra -I.

RM		= rm -f

CC		=	gcc

OBJS	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME) : 	$(OBJS)
	gcc $(OBJS) -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

.PHONY	:	all clean flcean re
