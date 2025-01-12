PROGRAM_NAME = TemplateClass

CPPFLAGS = -Wall -Werror -Wextra -std=c++11
CC = c++ $(CPPFLAGS)

HEADERS = Array.hpp
SOURCES = main.cpp Array.cpp
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