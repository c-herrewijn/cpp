NAME	= identify
CFLAGS	= -Wall -Wextra -Werror -Wconversion -std=c++11
INCLUDE = .

SRCS	= main.cpp Identify.cpp

OBJ_DIR = obj
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))


all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $^ -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	c++ -c $(CFLAGS) -I $(INCLUDE) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
