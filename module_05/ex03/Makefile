NAME	= form
CFLAGS	= -Wall -Wextra -Werror -std=c++11
INCLUDE = .

SRCS	= main.cpp Bureaucrat.cpp AForm.cpp \
		  PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp \
		  Intern.cpp ASCIItrees.cpp

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
