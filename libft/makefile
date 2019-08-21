# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 18:37:35 by thflahau          #+#    #+#              #
#    Updated: 2019/06/16 18:41:37 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

INCLUDE	=	.

CFLAGS	=	-Wall -Wextra -Werror -I $(INCLUDE) -c

NAME	=	libft.a

include ../libftsources.mk

OBJS	=	$(LIBS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(LIBS)
	ar -cq $@ $(OBJS)
	ranlib $@

%.o		: %.c	libft.h
	@$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	/bin/rm -f $(OBJS)

fclean	: clean
	/bin/rm -f $(NAME)

re		: fclean all

.SILENT	: all clean fclean $(NAME)
.phony	: $(NAME) clean fclean re
