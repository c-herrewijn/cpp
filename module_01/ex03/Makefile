NAME	= unnecessary_violence
CFLAGS	= -Wall -Wextra -Werror -std=c++98
INCLUDE = .

SRCS	= HumanA.cpp HumanB.cpp Weapon.cpp main.cpp

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

lint:
	astyle --options=../linter.txt ./*.cpp,*.h

.PHONY: all clean fclean re lint
