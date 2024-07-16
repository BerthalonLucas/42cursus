# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 19:53:46 by lberthal          #+#    #+#              #
#    Updated: 2023/11/02 18:05:24 by lberthal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c  ft_bzero.c   ft_memcpy.c \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_atoi.c  ft_strnstr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_strmapi.c ft_striteri.c \
		ft_itoa.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = libft.a

all:	${NAME}

${NAME}:	${OBJS}
		ar rcs ${NAME} ${OBJS}

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re :	fclean ${NAME}

# test :
# 	clear
# 	${CC} ${Cflags} -c main.c -o main.o
# 	${CC} ${Cflags} -o main main.o -L. -lft -lbsd
# 	@echo "\n======================[   tests    ]======================"
# 	@./main
# 	@echo "\n======================[ all done ! ]======================"

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY : all clean fclean re