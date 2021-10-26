SRC		= $(shell find . -type f -name "*.cpp")
INC		= $(shell find . -type f -name "*.hpp")
OBJ		= $(SRC:.cpp=.o)
CC		= clang++
CFLAGS	= -Wall -Wextra -Werror -Wno-unused -std=c++98
NAME	= main.out

all:		$(NAME)

.cpp.o:		$(INC)
				@$(CC) $(CFLAGS) -Iinc -c $< -o $@ && echo "generating object file '$@'"

$(NAME):	$(OBJ)
				@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) && echo "generating executable file '$@'"

clean:
				@rm -vrf $(OBJ)

fclean:		clean
				@rm -vrf $(NAME)

run:		all
				@./$(NAME)

re:			fclean all

.PHONY:		clean fclean run re
