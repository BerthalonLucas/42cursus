# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 06:23:29 by lberthal          #+#    #+#              #
#    Updated: 2024/05/08 06:28:43 by lberthal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NANE = test

CC = gcc

OBJS_DIR = .objs

OBJS = $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))

SRC_DIR 	=	./srcs
SRC 		=	$(wildcard $(SRC_DIR)/*.c)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)
		
$(NAME) : $(OBJS)
			$(CC) -o $@ $^ $(CFLAGS)
			@echo "Compilation OK"

$(OBJS_DIR)/%.o 	: %.c
			mkdir -p $(dir $@)
			$(CC) -o $@ -c $^ $(CFLAGS)
			@echo "converting $< to $@ OK"

clean 	:
			rm -rf $(OBJS)

fclean 	: clean
			$(RM) $(NAME)
			rm -rf $(OBJS_DIR)

re		: fclean all
