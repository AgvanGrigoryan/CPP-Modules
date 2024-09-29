#include "Ice.hpp"

Ice::Ice() : type("ice") {
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : type("ice") {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice Destructor called" << std::endl;
}

Ice::operator=(const Ice& other) {
	if (*this != other)
		this->type = other.type;
	std::cout << "Ice copy assignment operator called" << std::endl;
};

virtual AMateria* clone() const {
	return (new Ice(this));
}