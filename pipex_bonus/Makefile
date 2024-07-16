# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 21:22:42 by lucas             #+#    #+#              #
#    Updated: 2024/06/03 06:57:19 by lberthal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	pipex

MLX42		=	./MLX

SRC_DIR 	=	./srcs
SRC 		=	srcs/childs.c \
				srcs/files_check.c \
				srcs/forking.c \
				srcs/free.c \
				srcs/init.c \
				srcs/path_utils.c \
				srcs/path.c \
				srcs/pipex.c \

INCLUDES	=	./includes

NORMINETTE = 	$(shell norminette $(SRC) $(INCLUDES) | grep -c "Error")

OBJS_DIR 	= .objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))

CC 		= gcc

LIBFT	= ./libft/libft.a

CFLAGS 	= -Wall -Wextra -Werror -g3
CFLAGSD = -Wall -Wextra -Werror -g3 -fsanitize=address


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
			@$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIBFT)
			@echo "$(BLUE)Compilation$(END) $(VC)PIPEX$(END) $(GREEN)OK$(END)"


$(LIBFT) : 
			@make re -s -C ./libft

bonus	:	$(NAME_BONUS)

$(OBJS_DIR)/%.o 	: %.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -o $@ -c $^ 

norm	: 
			@if [ $(NORMINETTE) -eq 0 ]; then \
				echo "\n\n$(BLUE)================================================"; \
				echo "[          $(GREEN)   NORMINETTES PIPEX OK$(BLUE)             ]"; \
				echo "$(BLUE)================================================$(END)\n\n"; \
			else \
				echo "\n$(BLUE)=============================================="; \
				echo "[          $(RED)NORMINETTES PIPEX ERRORS$(BLUE)          ]"; \
				echo "$(BLUE)==============================================$(END)\n"; \
				norminette $(SRC) | grep "Error"; \
				norminette $(INCLUDES) | grep "Error"; \
				echo "\n"; \
			fi

clean 	:
			@rm -rf .objs
			@echo "$(YELLOW)clean$(END) $(VC)SO_LONG$(END) $(GREEN)OK$(END)"

fclean 	: clean
			@$(RM) $(NAME)
			@echo "$(YELLOW)fclean$(END) $(VC)SO_LONG$(END) $(GREEN)OK$(END)"
			@make -s -C ./libft fclean

debug 	: $(LIBFT) $(OBJS)
			$(CC) $(CFLAGSD) $(SRC) -o $(NAME) $(LIBFT)
			@echo "$(BLUE)Compilation$(END) $(VC)PIPEX$(END) $(GREEN)OK$(END) $(YELLOW)DEBUG$(END)"

re 		: fclean all
