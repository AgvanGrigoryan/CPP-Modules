#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat default Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) {
	this->type = other.type;
	std::cout << "Cat copy Constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	this->type = other.type;
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Сat meows" << std::endl;
}