NAME	= materia
# CFLAGS	= -Wall -Wextra -Werror
CFLAGS	= ""
INCLUDE = .

SRCS	= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp ICharacter.cpp IMateriaSource.cpp MateriaSource.cpp
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

lint:
	astyle --options=../linter.txt ./*.cpp,*.h

.PHONY: all clean fclean re lint
