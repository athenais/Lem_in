# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libftsources.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/16 17:59:28 by thflahau          #+#    #+#              #
#    Updated: 2019/06/16 18:18:51 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBS	=	ft_isaligned.c			ft_isblank.c				\
			ft_isdigit.c			ft_isprintable.c			\
			ft_memset.c				ft_putchar.c				\
			ft_putnstr.c			ft_putstr_endl.c			\
			ft_putstr.c				ft_strnew.c					\
			ft_strlen.c				ft_strnjoinfree.c			\
			ft_fast_bzero.c 		ft_word_count.c 			\
			ft_strrchr.c			ft_atoi_parsing.c			\
			ft_strdup.c				ft_strndup.c				\
			ft_strchr.c				ft_strsub.c					\
			ft_strcmp.c				ft_strncmp.c				\
			ft_is32bits.c			ft_putnbr_light.c			\
			ft_printf.c				ft_putchar_fd.c				\
			ft_putstr_fd.c			ft_putendl_fd.c	 			\
			ft_itoa.c				ft_memcpy.c					\
			ft_abs.c				ft_min.c				 	\
			ft_readline.c			ft_u32len.c					\
			ft_strcat.c				ft_putstr_endl_free.c		\
			ft_isvalidformat.c		ft_variadic_freeing.c

LIBSRCS	=	$(addprefix $(LIBDIR)/, $(LIBS))
