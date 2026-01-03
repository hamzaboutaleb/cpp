SRC_FILES = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
			 RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

SRC_DIR = src/
OBJ_DIR = build/
INCLUDE_DIR = includes/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INCLUDE_DIR)
NAME = bureaucrat

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re