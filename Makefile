NAME = get_next_line

# FLAG = -Wall -Werror -Wextra #-fsanitize=address -ggdb
# LFLAGS = -L. -lft

SRC = 	get_next_line.c	\
		main.c			\

HDR =	get_next_line.h \

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -I $(HDR) -L. -lft
	@ echo ~~ready~~

clean:
	@ /bin/rm -f $(OBJ)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all
