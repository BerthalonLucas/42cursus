# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas <lucas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 15:39:27 by lucas             #+#    #+#              #
#    Updated: 2023/11/24 15:49:24 by lucas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
AR 			= ar -rc
SRC 		= ft_printf.c \

OBJS 		= $(SRC:.c=.o) 

all 	: $(NAME)

$(NAME) : $(OBJS) 
			@$(AR) $(NAME) $(OBJS)

%.o 	: %.c
			@$(CC) $(CFLAGS) -c $< -o $@  

clean 	:
			@$(RM) $(OBJS) $(OBJSBONUS)

fclean 	: clean
			@$(RM) $(NAME)

re 		: fclean all $(NAME)

# bonus : $(OBJSBONUS)
# 		@$(AR) $(NAME) $(OBJSBONUS)

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
# 	gcc -nostartfiles -shared -o libft.so $(OBJ)