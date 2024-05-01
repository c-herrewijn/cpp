NAME	= PmergeMe
CFLAGS	= -Wall -Wextra -Werror -std=c++11

SRCS	= main.cpp PmergeMe.cpp
OBJ_DIR = obj
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $^ -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	c++ -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

lint:
	astyle --options=../linter.txt ./*.cpp,*.hpp,*.tpp

.PHONY: all clean fclean re lint
