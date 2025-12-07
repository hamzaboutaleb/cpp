SRC_FILES = main.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

SRC_DIR = src/
OBJ_DIR = build/
INCLUDE_DIR = include/

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -std=c++98
NAME = ex04

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re