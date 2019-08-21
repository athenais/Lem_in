# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 22:08:10 by abrunet           #+#    #+#              #
#    Updated: 2019/06/16 19:07:07 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	lem-in

####### DIRECTORIES #######
HDR			=	include
LIBDIR		=	libft
SRCDIR		=	srcs
OBJDIR		=	obj

###### MAKE VARIABLES #####
STDOUT		=	/dev/fd/1
MODE		=

ifeq '$(MODE)' 'silent'
	STDOUT	=	/dev/null
endif

########## FLAGS ##########
CFLAGS		=	-Wall						\
				-Wextra						\
				-Werror						\
				-Wpadded					\
				-std=c99					\
				-pedantic					\
				-O3

INC			=	-I $(HDR)
CLIBFT		=	-L $(LIBDIR) -lft

######### SOURCES #########
SRC			=	main						parsing						\
				parsing_vertices			memory						\
				errors						parsing_edges				\
				connection_list				hash						\
				queue						stacks						\
				algorithm_memory			algorithm					\
				breadth_first_search		visual						\
				movements					graph_manipulation			\
				list						list_copy					\
				distribution_formula		algorithm_overlaps			\
				distribution				algorithm_unused_paths		\
				graph_modifications			algorithm_pathfinding_hard	\
				parsing_memory				movements_buffer			\
				algorithm_pathfinding_simple

HDRFILES	=	$(filter %.h, $(shell find $(HDR)))

LIBFT		=	$(LIBDIR)/libft.a

SRCS		=	$(addprefix $(SRCDIR), $(SRC))
OBJ 		=	$(patsubst %,$(OBJDIR)/%.o, $(SRC))

include libftsources.mk

######### COLORS ##########
STD			=	\033[0m
GREEN		=	\033[1;32m
RED			=	\033[1;31m
YELLOW		=	\033[1;33m

########## RULES ##########
all				: $(NAME)

$(NAME)			: $(LIBFT) $(OBJ)
	printf "$(YELLOW)%-35s$(STD)" "Building $@... " > $(STDOUT)
	gcc $(CFLAGS) $(OBJ) -o $@ $(CLIBFT)
	echo "$(GREEN)DONE$(STD)" > $(STDOUT)

$(LIBFT)		: $(LIBDIR)/libft.h $(LIBSRCS)
	printf "$(YELLOW)%-35s$(STD)" "Building $@... " > $(STDOUT)
	make -C $(LIBDIR)
	echo "$(GREEN)DONE$(STD)" > $(STDOUT)

$(OBJDIR)/%.o	: $(SRCDIR)/%.c $(HDRFILES)
	@mkdir -p $(OBJDIR)
	@echo " > Compiling $(SRCDIR)/$*..." > $(STDOUT)
	@gcc $(CFLAGS) $(INC) -c $< -o $@

silent			:
	@make MODE=silent

clean			:
	/bin/rm -rf $(OBJDIR)
	make clean -C $(LIBDIR)
	echo "$(RED)Object files removed$(STD)" > $(STDOUT)

fclean			: clean
	/bin/rm -rf $(NAME)
	make fclean -C $(LIBDIR)
	echo "$(RED)$(NAME) removed$(STD)" > $(STDOUT)

re				: fclean all

.phony			: all $(LIBFT) silent clean fclean re
.SILENT			: $(NAME) $(LIBFT) clean fclean
