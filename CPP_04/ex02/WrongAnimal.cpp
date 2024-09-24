#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	this->type = other.type;
	std::cout << "WrongAnimal copy Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	this->type = other.type;
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal make some sound" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return (type);
}