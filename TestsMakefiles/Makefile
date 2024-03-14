NAME 	= library.a

ARC 	= lib.a

CC 		= gcc

OBJS_DIR 	= .objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))
CFLAGS 	= -Wall -Wextra -Werror

SRC 	=	src/test.c		\
			src/test2.c		\
			src/main.c		

NORMINETTE = 	$(shell norminette $(SRC) | grep -c "Error")

COLOUR_RED		=\033[0;31m
COLOUR_GREEN	=\033[0;32m
COLOUR_YELLOW	=\033[0;33m
COLOUR_BLUE		=\033[0;34m
COLOUR_END		=\033[0m

all		: $(NAME) clean
			@if [ $(NORMINETTE) -eq 0 ]; then \
				echo "$(COLOUR_BLUE)=========================================="; \
				echo "[          $(COLOUR_GREEN)NORMINETTES OK$(COLOUR_BLUE)            ]"; \
				echo "$(COLOUR_BLUE)==========================================$(COLOUR_END)"; \
			else \
				echo "$(COLOUR_BLUE)=========================================="; \
				echo "[          $(COLOUR_RED)NORMINETTES ERRORS$(COLOUR_BLUE)            ]"; \
				echo "$(COLOUR_BLUE)==========================================$(COLOUR_END)"; \
				norminette $(SRC) | grep "Error"; \
			fi

$(NAME) : $(OBJS) 
			@$(CC) -o $@ $^ $(CFLAGS)
			@echo "Compilation $(COLOUR_GREEN)OK$(COLOUR_END)"

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

