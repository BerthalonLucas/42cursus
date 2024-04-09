# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 02:59:42 by lberthal          #+#    #+#              #
#    Updated: 2024/04/09 20:41:14 by lberthal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	push_swap

NAME_BONUS	=	checker

SRC_BONUS_DIR 	=	./bonus_checker/src_bonus
SRC_BONUS 		=	$(wildcard $(SRC_BONUS_DIR)/*.c)

OBJS_BONUS		= $(addprefix $(OBJS_DIR)/, $(SRC_BONUS:.c=.o))

SRC_DIR 	=	./srcs
SRC 		=	$(wildcard $(SRC_DIR)/*.c)
				
OBJS_DIR 	= .objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))

CC 		= gcc

LIBFT	= ./libft/libft.a

CFLAGS 	= -Wall -Wextra -Werror -g3


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

bonus	:	$(NAME_BONUS)

$(NAME_BONUS)	:	$(LIBFT) $(OBJS_BONUS)
			@$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) -o $(NAME_BONUS)
			@echo "$(BLUE)Compilation$(END) $(VC)CHECKER$(END) $(GREEN)OK$(END)"

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
