# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 21:22:42 by lucas             #+#    #+#              #
#    Updated: 2024/05/30 04:57:49 by lberthal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	so_long

MLX42		=	./MLX

SRC_DIR 	=	./srcs
SRC 		=	$(SRC_DIR)/So_long.c				\
				$(SRC_DIR)/collect.c				\
				$(SRC_DIR)/exit.c					\
				$(SRC_DIR)/init.c					\
				$(SRC_DIR)/floor.c					\
				$(SRC_DIR)/free_alloc.c				\
				$(SRC_DIR)/hooks.c					\
				$(SRC_DIR)/map_parsing.c			\
				$(SRC_DIR)/map_parsing_utils.c		\
				$(SRC_DIR)/map_parsing_utils1.c		\
				$(SRC_DIR)/mlx_entries.c			\
				$(SRC_DIR)/player.c					\
				$(SRC_DIR)/playerimg.c				\
				$(SRC_DIR)/wall.c					\

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


$(NAME)	:	$(LIBFT) norm $(OBJS)
			@cd $(MLX42) && cmake  -B build --log-level=ERROR && cmake --build build -j4 -- -s
			@$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIBFT) $(MLX42)/build/libmlx42.a -Iinclude -I ./MLX/include/MLX42 -lglfw -lm
			@echo "$(BLUE)Compilation$(END) $(VC)SO_LONG$(END) $(GREEN)OK$(END)"


$(LIBFT) : 
			@make re -s -C ./libft

bonus	:	$(NAME_BONUS)

$(OBJS_DIR)/%.o 	: %.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -o $@ -c $^ 

norm	: 
			@if [ $(NORMINETTE) -eq 0 ]; then \
				echo "\n\n$(BLUE)=================================================="; \
				echo "[          $(GREEN)   NORMINETTES SO_LONG OK$(BLUE)             ]"; \
				echo "$(BLUE)==================================================$(END)\n\n"; \
			else \
				echo "\n$(BLUE)================================================"; \
				echo "[          $(RED)NORMINETTES SO_LONG ERRORS$(BLUE)          ]"; \
				echo "$(BLUE)================================================$(END)\n"; \
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
			cd $(MLX42) && cmake -B build && cmake --build build -j4
			$(CC) $(CFLAGSD) $(SRC) -o $(NAME) $(LIBFT) $(MLX42)/build/libmlx42.a -Iinclude -I ./MLX/include/MLX42 -lglfw -lm
			@echo "$(BLUE)Compilation$(END) $(VC)SO_LONG$(END) $(GREEN)OK$(END) $(YELLOW)DEBUG$(END)"

re 		: fclean all
