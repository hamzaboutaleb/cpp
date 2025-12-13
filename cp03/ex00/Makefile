SRCS_FILES = main.cpp ClapTrap.cpp
OBJS_FILES = $(SRCS_FILES:.cpp=.o)

SRC_DIR = ./src
OBJ_DIR = ./build
INC_DIR = ./include

SRCS = $(addprefix $(SRC_DIR)/, $(SRCS_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJS_FILES))

NAME = claptrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -std=c++98
RM = rm -f
MKDIR = mkdir -p

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re