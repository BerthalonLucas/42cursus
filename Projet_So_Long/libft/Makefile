# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 19:53:46 by lberthal          #+#    #+#              #
#    Updated: 2024/05/28 23:09:36 by lberthal         ###   ########.fr        #
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
				src/mallocs/ft_free_ptr.c		\
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
				src/printf/ft_printf_utils4.c	\
				src/printf/ft_printf.c			\
				src/fprintf/ft_fprintf_utils1.c	\
				src/fprintf/ft_fprintf_utils2.c	\
				src/fprintf/ft_fprintf_utils3.c	\
				src/fprintf/ft_fprintf.c			\
				src/gnl/get_next_line.c			\
				src/gnl/get_next_line_utils.c	\
				

SHELL = /bin/bash


ARC 	= lib.a

CC 		= gcc

TOTAL 	= $(words $(SRC))

COUNT 	= 0
COMPILED = 0


OBJS_DIR 	= .objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))
CFLAGS 	= -Wall -Wextra -Werror -g3

NORMINETTE = 	$(shell norminette $(SRC) | grep -c "Error")

RED			=\033[0;31m
GREEN		=\033[0;32m
YELLOW		=\033[0;33m
BLUE		=\033[0;34m
VC			=\033[0;35m
CYAN		=\033[0;96m
DARK_GRAY	=\033[0;90m
END			=\033[0m



define color_progress
$(if $(shell test $(1) -gt 66 && echo true),$(GREEN),$(if $(shell test $(1) -gt 33 && echo true),$(YELLOW),$(RED)))
endef

define progress_bar
@$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
@$(eval PROGRESS_PERCENT=$(shell echo $$((($(COMPILED) * 100) / $(TOTAL)))))
@printf "$(CYAN)["
@for number in `seq 1 $(COMPILED)`; do printf "$(call color_progress,$(PROGRESS_PERCENT))▓"; done
@for number in `seq 1 $$(($(TOTAL) - $(COMPILED)))`; do printf "$(GRAY)░"; done
@printf "$(CYAN)] ($(COMPILED)/$(TOTAL))$(END)\r"
endef

define moon_phase_animation
@PHASES=("🌑 " "🌒 " "🌓 " "🌔 " "🌕 " "🌖 " "🌗 " "🌘 "); \
IDX=$$(($(COMPILED) % 8)); \
printf "\r$${PHASES[$$IDX]}"
endef




define project_name
@echo "                                              ";
@echo " _____ __ __    __    _____ _____ _____ _____ ";
@echo "|     |  |  |  |  |  |     | __  |   __|_   _|";
@echo "| | | |_   _|  |  |__|-   -| __ -|   __| | |  ";
@echo "|_|_|_| |_|    |_____|_____|_____|__|    |_|  ";
endef

PROJECT_NAME : 
			$(call project_name)


all		: PROJECT_NAME $(NAME)

$(NAME) : norm $(OBJS) 
			@$(AR) $(NAME) $(OBJS)
			@printf "\n"
			@echo -e "$(BLUE)Compilation$(END) $(VC)LIBFT$(END) $(GREEN)OK$(END)\n"

$(OBJS_DIR)/%.o 	: %.c
			@mkdir -p $(dir $@)
			@$(CC) -o $@ -c $^ $(CFLAGS)
			$(call progress_bar)
			$(call moon_phase_animation)

$(ARC)	: $(OBJS)



norm	: 
			@if [ $(NORMINETTE) -eq 0 ]; then \
				echo -e "\n\n$(BLUE)=========================================="; \
				echo -e "[          $(GREEN)   NORMINETTES OK$(BLUE)             ]"; \
				echo -e "$(BLUE)==========================================$(END)\n\n"; \
			else \
				echo -e "\n$(BLUE)=========================================="; \
				echo -e "[          $(RED)NORMINETTES ERRORS$(BLUE)          ]"; \
				echo -e "$(BLUE)==========================================$(END)\n"; \
				norminette $(SRC) | grep "Error"; \
				printf "\n"; \
			fi


archive	: $(ARC)
			@ar -r $(ARC) $(OBJS)
			@echo "preview of the archive :"
			@echo "-------------------------------------------"
			@ar tv $(ARC)
			@$(RM) $(OBJS)
			@$(RM) $(ARC)

clean 	:
			@rm -rf $(OBJS)
			@echo -e "$(YELLOW)clean$(END) $(VC)LIBFT$(END) $(GREEN)OK$(END)"

fclean 	: clean
			@$(RM) $(NAME)
			@$(RM) $(ARC)
			@rm -rf $(OBJS_DIR)
			@echo -e "$(YELLOW)fclean$(END) $(VC)LIBFT$(END) $(GREEN)OK$(END)"

re 		: fclean all
