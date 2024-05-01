# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas <lucas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 21:22:42 by lucas             #+#    #+#              #
#    Updated: 2024/04/18 21:32:19 by lucas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	so_long

MLX42		=	.MLX/MLX42

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
			@cmake $(MLX42) -B $(MLX42)/build && make -C $(MLX42)/build -j4
			$(CC) $(CFLAGS) -Iinclude -ldl -lglfw -pthread -lm $(SRC) $(LIBFT) $(MLX42)/build/libmlx42.a -o $(NAME)
			@echo "$(BLUE)Compilation$(END) $(VC)SO_LONG$(END) $(GREEN)OK$(END)"


$(LIBFT) : 
			@make re -s -C ./libft

bonus	:	$(NAME_BONUS)

$(OBJS_DIR)/%.o 	: %.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -o $@ -c $^ 

clean 	:
			@rm -rf .objs
			@echo "$(YELLOW)clean$(END) $(VC)SO_LONG$(END) $(GREEN)OK$(END)"

fclean 	: clean
			@$(RM) $(NAME)
			@echo "$(YELLOW)fclean$(END) $(VC)SO_LONG$(END) $(GREEN)OK$(END)"
			@make -s -C ./libft fclean

re 		: fclean all