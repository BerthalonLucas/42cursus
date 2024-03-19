# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 02:59:42 by lberthal          #+#    #+#              #
#    Updated: 2024/03/19 15:51:39 by lberthal         ###   ########.fr        #
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

TOTAL 	= $(words $(SRC))

RED			=\033[0;31m
GREEN		=\033[0;32m
YELLOW		=\033[0;33m
BLUE		=\033[0;34m
VC			=\033[0;35m
CYAN		=\033[0;96m
DARK_GRAY	=\033[0;90m
END			=\033[0m

define progress_bar
@$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
@printf "$(CYAN)Progression PUSH_SWAP: ["
@for number in `seq 1 $(COMPILED)`; do printf "$(GREEN)▓"; done
@for number in `seq 1 $$(($(TOTAL) - $(COMPILED)))`; do printf "$(DARK_GRAY)-"; done
@printf "$(CYAN)] ($(COMPILED)/$(TOTAL))$(END)\r"
endef

all		:	$(NAME)

$(NAME)	:	$(LIBFT) $(OBJS)
			@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
			@echo "$(BLUE)Compilation$(END) $(VC)PUSH_SWAP$(END) $(GREEN)OK$(END)"
$(LIBFT) : 
			@make -s -C ./libft


$(OBJS_DIR)/%.o 	: %.c
			@mkdir -p $(dir $@)
			@$(CC) -o $@ -c $^ $(CFLAGS)
			$(call progress_bar)
			
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