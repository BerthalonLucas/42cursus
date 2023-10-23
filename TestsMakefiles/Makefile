NAME 	= library.a
ARC 	= lib.a
OBJS 	= $(SRC:.c=.o)
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
SRC 	=	test.c		\
			test2.c		\
			main.c		

all 	: $(NAME) clean
			@echo "=========================================="
			@echo "[          NORMINETTES ERRORS            ]"
			@echo "=========================================="
			@norminette $(SRC)
			@-./tmp

$(NAME) : $(OBJS) 
			@$(CC) -o $@ $^ $(CFLAGS)
			@echo "Compilation OK"
			
%.o 	: %.c
			@$(CC) -o $@ -c $^ $(CFLAGS)
			@echo "converting $< to $@ OK"

$(ARC)	: $(OBJS)

archive	: $(ARC)
			@ar -r $(ARC) $(OBJS)
			@echo "preview of the archive :"
			@echo "-------------------------------------------"
			@ar tv $(ARC)
			@$(RM) $(OBJS)

clean 	:
			@$(RM) $(OBJS)
			@echo "clean OK"

fclean 	: clean
			@$(RM) $(NAME)
			@$(RM) $(ARC)
			@echo "fclean OK"

re 		: fclean all

