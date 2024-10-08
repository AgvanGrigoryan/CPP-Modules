#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog default Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
	this->type = other.type;
	std::cout << "Dog copy Constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other) {
	this->type = other.type;
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Dog barks" << std::endl;
}