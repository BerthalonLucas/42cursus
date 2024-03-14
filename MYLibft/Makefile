# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 19:53:46 by lberthal          #+#    #+#              #
#    Updated: 2024/03/14 02:01:19 by lberthal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a
AR 			= ar -rc
SRC 		=	src/verif/ft_isalpha.c			\
				src/verif/ft_isdigit.c			\
				src/verif/ft_isalnum.c			\
				src/verif/ft_isascii.c			\
				src/verif/ft_isprint.c			\
				src/verif/ox_m_r.c				\
				src/strings/ft_strlcat.c		\
				src/strings/ft_strlcpy.c		\
				src/strings/ft_strchr.c			\
				src/strings/ft_strrchr.c		\
				src/strings/ft_strncmp.c		\
				src/strings/ft_toupper.c		\
				src/strings/ft_tolower.c		\
				src/strings/ft_strlen.c			\
				src/strings/ft_strnstr.c		\
				src/strings/ft_atoi.c			\
				src/strings/ft_strdup.c			\
				src/strings/ft_substr.c			\
				src/strings/ft_strjoin.c		\
				src/strings/ft_strtrim.c		\
				src/strings/ft_split.c			\
				src/strings/ft_strmapi.c		\
				src/strings/ft_striteri.c		\
				src/strings/ft_putchar_fd.c		\
				src/strings/ft_putendl_fd.c		\
				src/strings/ft_putstr_fd.c		\
				src/memory/ft_memmove.c			\
				src/memory/ft_memset.c			\
				src/memory/ft_bzero.c			\
				src/memory/ft_memcpy.c			\
				src/memory/ft_memchr.c			\
				src/memory/ft_memcmp.c			\
				src/mallocs/ft_calloc.c			\
				src/mallocs/ft_realloc.c		\
				src/numbers/ft_itoa.c			\
				src/numbers/ft_putnbr_fd.c		\
				src/chain_list/ft_lstnew.c		\
				src/chain_list/ft_lstadd_front.c\
				src/chain_list/ft_lstsize.c		\
				src/chain_list/ft_lstlast.c		\
				src/chain_list/ft_lstadd_back.c	\
				src/chain_list/ft_lstdelone.c	\
				src/chain_list/ft_lstclear.c	\
				src/chain_list/ft_lstiter.c		\
				src/chain_list/ft_lstmap.c 		\
				src/printf/ft_printf_utils1.c	\
				src/printf/ft_printf_utils2.c	\
				src/printf/ft_printf_utils3.c	\
				src/printf/ft_printf.c			\
				src/gnl/get_next_line.c			\
				src/gnl/get_next_line_utils.c	\
				

# OBJSBONUS 	= $(SRCBONUS:.c=.o)

ARC 	= lib.a

CC 		= gcc

OBJS_DIR 	= .objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))
CFLAGS 	= -Wall -Wextra -Werror

NORMINETTE = 	$(shell norminette $(SRC) | grep -c "Error")

COLOUR_RED		=\033[0;31m
COLOUR_GREEN	=\033[0;32m
COLOUR_YELLOW	=\033[0;33m
COLOUR_BLUE		=\033[0;34m
COLOUR_END		=\033[0m

all		: $(NAME) clean
			@if [ $(NORMINETTE) -eq 0 ]; then \
				echo "$(COLOUR_BLUE)=========================================="; \
				echo "[          $(COLOUR_GREEN)   NORMINETTES OK$(COLOUR_BLUE)             ]"; \
				echo "$(COLOUR_BLUE)==========================================$(COLOUR_END)"; \
			else \
				echo "$(COLOUR_BLUE)=========================================="; \
				echo "[          $(COLOUR_RED)NORMINETTES ERRORS$(COLOUR_BLUE)          ]"; \
				echo "$(COLOUR_BLUE)==========================================$(COLOUR_END)"; \
				norminette $(SRC) | grep "Error"; \
			fi

$(NAME) : $(OBJS) 
			@$(AR) $(NAME) $(OBJS)

# $(NAME) : $(OBJS) 
# 			@$(CC) -o $@ $^ $(CFLAGS)
# 			@echo "Compilation $(COLOUR_GREEN)OK$(COLOUR_END)"

$(OBJS_DIR)/%.o 	: %.c
			@mkdir -p $(dir $@)
			@$(CC) -o $@ -c $^ $(CFLAGS)
			@echo "converting $< to $@ $(COLOUR_GREEN)OK$(COLOUR_END)"

$(ARC)	: $(OBJS)

archive	: $(ARC)
			@ar -r $(ARC) $(OBJS)
			@echo "preview of the archive :"
			@echo "-------------------------------------------"
			@ar tv $(ARC)
			@$(RM) $(OBJS)
			@$(RM) $(ARC)

clean 	:
			@rm -rf $(OBJS)
			@echo "clean $(COLOUR_GREEN)OK$(COLOUR_END)"

fclean 	: clean
			@$(RM) $(NAME)
			@$(RM) $(ARC)
			@rm -rf $(OBJS_DIR)
			@echo "fclean $(COLOUR_GREEN)OK$(COLOUR_END)"

re 		: fclean all



# all 	: $(NAME)

# $(NAME) : $(OBJS) 
# 			@$(AR) $(NAME) $(OBJS)

# %.o 	: %.c
# 			@$(CC) $(CFLAGS) -c $< -o $@  

# clean 	:
# 			@$(RM) $(OBJS)

# fclean 	: clean
# 			@$(RM) $(NAME)

# re 		: fclean all $(NAME)

# bonus : $(OBJSBONUS)
# 		@$(AR) $(NAME) $(OBJSBONUS)

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
# 	gcc -nostartfiles -shared -o libft.so $(OBJ)
