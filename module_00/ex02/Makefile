NAME	= account
CFLAGS	= -Wall -Wextra -Werror -std=c++98
CC		= c++
INCLUDE = .

SRCS	= tests.cpp Account.cpp

OBJ_DIR = obj
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -I $(INCLUDE) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

lint:
	# astyle --options=linter.txt ./*.cpp,*.h
	astyle --options=linter.txt ./Account.cpp

.PHONY: all clean fclean re lint
