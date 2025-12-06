SRCS_FILES = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS_FILES = $(SRCS_FILES:.cpp=.o)

SRC_DIR = src/
INCLUDE_DIR = include
OBJ_DIR = build/

SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJS_FILES))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -std=c++98

NAME = zombie

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