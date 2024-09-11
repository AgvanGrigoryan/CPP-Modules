#include <iostream>

int	main(void) {
	std::string thisIsString("HI THIS IS BRAIN");
	std::string *stringPTR = &thisIsString;
	std::string &stringREF = thisIsString;

	std::cout << "The memory address of the string variable " << &thisIsString << std::endl;
	std::cout << "The memory address held by stringPTR " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF " << &stringREF << std::endl;

	std::cout << "The value of the string variable " << thisIsString << std::endl;
	std::cout << "The value pointed to by stringPTR " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF " << stringREF << std::endl;
	return (0);
}