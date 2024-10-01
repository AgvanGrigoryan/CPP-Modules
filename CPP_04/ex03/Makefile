PROGRAM_NAME = interface

CPPFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++ $(CPPFLAGS)

HEADERS = ICharacter.hpp Character.hpp AMateria.hpp Ice.hpp IMateriaSource.hpp MateriaSource.hpp
SOURCES = main.cpp Character.cpp AMateria.cpp Ice.cpp MateriaSource.cpp
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