# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 02:59:42 by lberthal          #+#    #+#              #
#    Updated: 2024/03/15 03:58:42 by lberthal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	push_swap

SRC 		=	main.c
				
CC 		= gcc



LIBFT	= ./libft/libft.a

CFLAGS 	= -Wall -Wextra -Werror -g3

OBJS_DIR 	= .objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))

NORMINETTE = 	$(shell norminette $(SRC) | grep -c "Error")

RED		=\033[0;31m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
BLUE	=\033[0;34m
VC		=\033[0;35m
CYAN	=\033[0;36m
END		=\033[0m

all		:	$(NAME)

$(NAME)	:	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT) : 
			@make -s -C ./libft


$(OBJS_DIR)/%.o 	: %.c
			@mkdir -p $(dir $@)
			@$(CC) -o $@ -c $^ $(CFLAGS)
			@echo "converting $< to $@ $(GREEN)OK$(END)"
			
norm	: 
			@if [ $(NORMINETTE) -eq 0 ]; then \
				echo "$(BLUE)=========================================="; \
				echo "[          $(GREEN)   NORMINETTES OK$(BLUE)             ]"; \
				echo "$(BLUE)==========================================$(END)"; \
			else \
				echo "$(BLUE)=========================================="; \
				echo "[          $(RED)NORMINETTES ERRORS$(BLUE)          ]"; \
				echo "$(BLUE)==========================================$(END)"; \
				norminette $(SRC) | grep "Error"; \
			fi
			
clean 	:
			@rm -rf ./*.o
			@echo "$(YELLOW)clean$(END) $(VC)PUSH_SWAP$(END) $(GREEN)OK$(END)"

fclean 	: clean
			@$(RM) $(NAME)
			@make -s -C ./libft fclean
			@echo "$(YELLOW)fclean$(END) $(VC)PUSH_SWAP$(END) $(GREEN)OK$(END)"

re 		: fclean all