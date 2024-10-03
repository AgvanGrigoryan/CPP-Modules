#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice Destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other)
		this->type = other.type;
	std::cout << "Ice copy assignment operator called" << std::endl;
	return (*this);
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}