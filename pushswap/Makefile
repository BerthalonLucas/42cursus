# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 02:59:42 by lberthal          #+#    #+#              #
#    Updated: 2024/04/07 09:14:56 by lberthal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	push_swap

SRC_DIR 	=	./srcs
SRC 		=	$(wildcard $(SRC_DIR)/*.c)
				
CC 		= gcc

LIBFT	= ./libft/libft.a

CFLAGS 	= -Wall -Wextra -Werror -g3

OBJS_DIR 	= .objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))

RED			=\033[0;31m
GREEN		=\033[0;32m
YELLOW		=\033[0;33m
BLUE		=\033[0;34m
VC			=\033[0;35m
CYAN		=\033[0;96m
DARK_GRAY	=\033[0;90m
END			=\033[0m

all		:	$(NAME)

$(NAME)	:	$(LIBFT) $(OBJS)
			@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
			@echo "$(BLUE)Compilation$(END) $(VC)PUSH_SWAP$(END) $(GREEN)OK$(END)"
$(LIBFT) : 
			@make re -s -C ./libft


$(OBJS_DIR)/%.o 	: %.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -o $@ -c $^ 

clean 	:
			@rm -rf .objs
			@echo "$(YELLOW)clean$(END) $(VC)PUSH_SWAP$(END) $(GREEN)OK$(END)"

fclean 	: clean
			@$(RM) $(NAME)
			@make -s -C ./libft fclean
			@echo "$(YELLOW)fclean$(END) $(VC)PUSH_SWAP$(END) $(GREEN)OK$(END)"

re 		: fclean all