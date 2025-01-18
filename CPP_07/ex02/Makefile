PROGRAM_NAME = TemplateClass

CPPFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++ $(CPPFLAGS)

HEADERS = Array.hpp
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJECTS)
	$(CC) $^ -o $(PROGRAM_NAME)

%.o: %.cpp Makefile $(HEADERS)
	$(CC) -c $< -o $@ -I.

clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(PROGRAM_NAME)
re: fclean all

.PHONY: all clean fclean re