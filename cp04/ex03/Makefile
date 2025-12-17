SRC_FILES = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

SRCS = $(addprefix src/, $(SRC_FILES))
OBJS = $(addprefix build/, $(OBJ_FILES))
include_dirs = -I include/ -I interface/

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror $(include_dirs) -std=c++98
NAME = program

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $(include_dirs) -c $< -o $@

clean:
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re