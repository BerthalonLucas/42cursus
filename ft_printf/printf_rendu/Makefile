# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 15:39:27 by lucas             #+#    #+#              #
#    Updated: 2024/02/02 01:57:25 by lberthal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
AR 			= ar -rc
CFLAGS 		= -Wall -Wextra -Werror
SRC 		= 	ft_printf.c \
				ft_printf_utils1.c \
				ft_printf_utils2.c \
				ft_printf_utils3.c \

OBJS 		= $(SRC:.c=.o) 

all 	: $(NAME)

$(NAME) : $(OBJS) 
			$(AR) $(NAME) $(OBJS)

%.o 	: %.c
			$(CC) $(CFLAGS) -c $< -o $@  

clean 	:
			$(RM) $(OBJS)

fclean 	: clean
			$(RM) $(NAME)

re 		: fclean all $(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)