PROGRAM_NAME = clapTrap

CPPFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++ $(CPPFLAGS)

HEADERS = ClapTrap.hpp
SOURCES = main.cpp ClapTrap.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJECTS)
	$(CC) $^ -o $(PROGRAM_NAME) -I.

%.o: %.cpp Makefile $(HEADERS)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(PROGRAM_NAME)
re: fclean all

.PHONY: all clean fclean re
