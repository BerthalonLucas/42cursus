# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 06:23:29 by lberthal          #+#    #+#              #
#    Updated: 2024/07/15 23:25:09 by lberthal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
SRC_DIR 	=	srcs
SRC 		=	$(wildcard $(SRC_DIR)/*.c)

INCLUDES	=	./include

NORMINETTE = 	$(shell norminette $(SRC) $(INCLUDES) | grep -c "Error")

OBJS_DIR 	= .objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror -g3
CFLAGSD = -Wall -Wextra -Werror -g3 -fsanitize=address
LDFLAGS = -lreadline -lncurses


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
			@$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LDFLAGS)
			@echo "$(BLUE)Compilation$(END) $(VC)test$(END) $(GREEN)OK$(END)"


bonus	:	$(NAME_BONUS)

$(OBJS_DIR)/%.o 	: %.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -o $@ -c $^ 

norm	: 
			@if [ $(NORMINETTE) -eq 0 ]; then \
				echo "\n\n$(BLUE)==================================================="; \
				echo "[          $(GREEN)   NORMINETTES test OK$(BLUE)             ]"; \
				echo "$(BLUE)===================================================$(END)\n\n"; \
			else \
				echo "\n$(BLUE)================================================="; \
				echo "[          $(RED)NORMINETTES test ERRORS$(BLUE)          ]"; \
				echo "$(BLUE)=================================================$(END)\n"; \
				norminette $(SRC) | grep "Error"; \
				norminette $(INCLUDES) | grep "Error"; \
				echo "\n"; \
			fi

clean 	:
			@rm -rf .objs
			@echo "$(YELLOW)clean$(END) $(VC)test$(END) $(GREEN)OK$(END)"

fclean 	: clean
			@$(RM) $(NAME)
			@echo "$(YELLOW)fclean$(END) $(VC)test$(END) $(GREEN)OK$(END)"

debug 	: $(OBJS)
			$(CC) $(CFLAGSD) $(SRC) -o $(NAME)
			@echo "$(BLUE)Compilation$(END) $(VC)test$(END) $(GREEN)OK$(END) $(YELLOW)DEBUG$(END)"

re 		: fclean all

