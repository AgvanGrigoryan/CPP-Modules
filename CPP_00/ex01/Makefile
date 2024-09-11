PROGRAM_NAME = phonebook

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++ $(CPPFLAGS)

HEADERS = PhoneBook.hpp Contact.hpp Utilities.hpp
SOURCES = main.cpp PhoneBook.cpp Contact.cpp Utilities.cpp
OBJECS = $(SOURCES:.cpp=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJECS)
	$(CPP) $^ -o $(PROGRAM_NAME) -I.

%.o: %.cpp Makefile $(HEADERS)
	$(CPP) -c $< -o $@

clean:
	rm -rf $(OBJECS)

fclean: clean
	rm -rf $(PROGRAM_NAME)

re: fclean all

.PHONY: all clean fclean re