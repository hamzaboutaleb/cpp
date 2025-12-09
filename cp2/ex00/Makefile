SRCS_FILE = main.cpp Fixed.cpp
OBJS_FILE = $(SRCS_FILE:.cpp=.o)

SRCS_DIR = src/
OBJS_DIR = build/
INCLUDE_DIR = include/

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILE))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILE))

NAME = FixedPoint
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re