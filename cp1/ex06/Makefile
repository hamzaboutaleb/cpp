SRCS_FILES = main.cpp Harl.cpp
OBJS_FILES = $(SRCS_FILES:.cpp=.o)

SRCS_DIR = src
OBJS_DIR = build
INC_DIR = include

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))
NAME = harlFilter
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re