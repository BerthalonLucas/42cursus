# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 21:22:42 by lucas             #+#    #+#              #
#    Updated: 2024/06/08 06:13:57 by lberthal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	philo

SRC_DIR 	=	./srcs
SRC 		=	$(wildcard $(SRC_DIR)/*.c)

INCLUDES	=	./includes

NORMINETTE = 	$(shell norminette $(SRC) $(INCLUDES) | grep -c "Error")

OBJS_DIR 	= .objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror -g3 -pthread
CFLAGSD = -Wall -Wextra -Werror -g3 -pthread -fsanitize=address


RED			=\033[0;31m
GREEN		=\033[0;32m
YELLOW		=\033[0;33m
BLUE		=\033[0;34m
VC			=\033[0;35m
CYAN		=\033[0;96m
DARK_GRAY	=\033[0;90m
END			=\033[0m

all		:	$(NAME)


$(NAME)	:	$(OBJS)
			@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
			@echo "$(BLUE)Compilation$(END) $(VC)PHILO$(END) $(GREEN)OK$(END)"


bonus	:	$(NAME_BONUS)

$(OBJS_DIR)/%.o 	: %.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -o $@ -c $^ 

norm	: 
			@if [ $(NORMINETTE) -eq 0 ]; then \
				echo "\n\n$(BLUE)================================================"; \
				echo "[          $(GREEN)   NORMINETTES PHILO OK$(BLUE)             ]"; \
				echo "$(BLUE)================================================$(END)\n\n"; \
			else \
				echo "\n$(BLUE)=============================================="; \
				echo "[          $(RED)NORMINETTES PHILO ERRORS$(BLUE)          ]"; \
				echo "$(BLUE)==============================================$(END)\n"; \
				norminette $(SRC) | grep "Error"; \
				norminette $(INCLUDES) | grep "Error"; \
				echo "\n"; \
			fi

clean 	:
			@rm -rf .objs
			@echo "$(YELLOW)clean$(END) $(VC)PHILO$(END) $(GREEN)OK$(END)"

fclean 	: clean
			@$(RM) $(NAME)
			@echo "$(YELLOW)fclean$(END) $(VC)PHILO$(END) $(GREEN)OK$(END)"

debug 	: $(OBJS)
			$(CC) $(CFLAGSD) $(SRC) -o $(NAME)
			@echo "$(BLUE)Compilation$(END) $(VC)PHILO$(END) $(GREEN)OK$(END) $(YELLOW)DEBUG$(END)"

re 		: fclean all
