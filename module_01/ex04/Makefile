NAME	= findreplace
CFLAGS	= -Wall -Wextra -Werror
INCLUDE = .

SRCS	= main.cpp

OBJ_DIR = obj
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $^ -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) -c $(CFLAGS) -I $(INCLUDE) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	@chmod +x ./test.sh
	@./test.sh

lint:
	astyle --options=../linter.txt ./*.cpp,*.h

.PHONY: all clean fclean re test lint
