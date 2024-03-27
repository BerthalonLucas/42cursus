# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 02:59:42 by lberthal          #+#    #+#              #
#    Updated: 2024/03/27 01:40:29 by lberthal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	push_swap

SRC_DIR 	=	./srcs
SRC 		=	$(wildcard $(SRC_DIR)/*.c)
				
CC 		= gcc

LIBFT	= ./libft/libft.a

CFLAGS 	= -Wall -Wextra -Werror -g3 #-fsanitize=address

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

define time_based_progress_bar
@echo "Démarrage de la compilation de $(VC)PUSH_SWAP$(END) ...\n"
@for i in `seq 1 30`; do \
    PERCENTAGE=$$((i * 100 / 30)); \
    FILLED=$$((i * 40 / 30)); \
    EMPTY=$$((40 - FILLED)); \
    printf "\r$(CYAN)Progression: [$(GREEN)"; \
    printf "%0.s▓" `seq 1 $$FILLED`; \
    printf "$(DARK_GRAY)"; \
    printf "%0.s░" `seq 1 $$EMPTY`; \
    printf "$(RESET)$(CYAN)] $$PERCENTAGE%%"; \
    sleep 0.1; \
done; \
echo ""; \
echo "Compilation terminée."
endef



all		:	$(NAME)

$(NAME)	:	$(LIBFT) $(OBJS)
			@$(if $(shell [ $(TOTAL) -lt 30 ] && echo true),\
				$(call time_based_progress_bar),\
				$(call progress_bar))
			@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
			@echo "$(BLUE)Compilation$(END) $(VC)PUSH_SWAP$(END) $(GREEN)OK$(END)"
$(LIBFT) : 
			@make re -s -C ./libft


$(OBJS_DIR)/%.o 	: %.c
			@mkdir -p $(dir $@)
			@$(CC) -o $@ -c $^ $(CFLAGS)

progress_bar_logic:
			$(call progress_bar)

time_based_progress_bar_logic:
			$(call time_based_progress_bar)

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
			@rm -rf .objs
			@echo "$(YELLOW)clean$(END) $(VC)PUSH_SWAP$(END) $(GREEN)OK$(END)"

fclean 	: clean
			@$(RM) $(NAME)
			@make -s -C ./libft fclean
			@echo "$(YELLOW)fclean$(END) $(VC)PUSH_SWAP$(END) $(GREEN)OK$(END)"

re 		: fclean all