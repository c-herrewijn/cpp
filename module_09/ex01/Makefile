NAME	= RPN
CFLAGS	= -Wall -Wextra -Werror -std=c++11

SRCS	= main.cpp RPN.cpp
OBJ_DIR = obj
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $^ -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

lint:
	astyle --options=../linter.txt ./*.cpp,*.hpp,*.tpp

.PHONY: all clean fclean re lint
