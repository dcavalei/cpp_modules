SRC		= $(shell find . -type f -name "*.cpp")
OBJ		= $(SRC:.cpp=.o)
CC		= clang++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= megaphone

all:		$(NAME)

.cpp.o:
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
				rm -rf $(OBJ)

fclean:		clean
				rm -rf $(NAME)

run:		all
				./$(NAME)

re:			fclean all

.PHONY:		clean fclean run re
