# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 21:22:42 by lucas             #+#    #+#              #
#    Updated: 2024/06/02 01:25:40 by lberthal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	so_long

MLX42		=	./MLX

SRC 		=	srcs/collect.c				\
				srcs/exit.c					\
				srcs/floor.c				\
				srcs/free_alloc.c			\
				srcs/hooks.c				\
				srcs/init.c					\
				srcs/map_parsing.c			\
				srcs/map_parsing_utils.c	\
				srcs/map_parsing_utils1.c	\
				srcs/mlx_entries.c			\
				srcs/So_long.c				\
				srcs/player.c				\
				srcs/playerimg.c			\
				srcs/wall.c					\

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


$(NAME)	:	$(LIBFT) $(OBJS) $(MLX42_LIB)
			@$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIBFT) $(MLX42)/build/libmlx42.a -Iinclude -I ./MLX/include/MLX42 -lglfw -lm
			@echo "$(BLUE)Compilation$(END) $(VC)SO_LONG$(END) $(GREEN)OK$(END)"


$(LIBFT) : 
			@make re -s -C ./libft

$(MLX42_LIB) :
			@cd $(MLX42) && cmake -B build && cmake --build build -j4

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
