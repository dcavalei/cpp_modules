SRC		= $(shell find . -name "*.cpp")
OBJ		= $(SRC:.cpp=.o)
CC		= clang++
CFLAGS	= -Wall -Wextra -Werror -Wno-unused
NAME	= megaphone

all:		$(NAME)

.c.o:
				$(CC) $(CFLAGS)	-c $< -o $@

$(NAME):	$(OBJ)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
				rm -rf $(OBJ)

fclean:		clean
				rm -rf $(NAME)

run:		all
				./$(NAME)

re:			clean fclean all
