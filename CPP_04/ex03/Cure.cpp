#include "Cure.hpp"

Cure::Cure() : type("cure") {
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : type("cure") {
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure Destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	if (*this != other)
		this->type = other.type;
	std::cout << "Cure copy assignment operator called" << std::endl;
	return (*this);
}

virtual AMateria* clone() const {
	return (new Cure(this));
}