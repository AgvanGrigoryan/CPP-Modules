#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default Constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	this->type = other.type;
	std::cout << "Animal copy Constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other) {
	this->type = other.type;
	std::cout << "Animal copy assignment operator called" << std::endl;
	return (*this);
}

std::string	Animal::getType() const {
	return (type);
}