PROGRAM_NAME = Polymorphism

CPPFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++ $(CPPFLAGS)

HEADERS = Brain.hpp\
			Animal.hpp Cat.hpp Dog.hpp\
			WrongAnimal.hpp WrongCat.hpp WrongDog.hpp
SOURCES = main.cpp Brain.cpp\
			Animal.cpp Cat.cpp Dog.cpp\
			WrongAnimal.cpp WrongCat.cpp WrongDog.cpp
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