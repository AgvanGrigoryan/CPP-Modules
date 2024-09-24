#include "WrongDog.hpp"

WrongDog::WrongDog() {
	type = "WrongDog";
	std::cout << "WrongDog default Constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& other) {
	this->type = other.type;
	std::cout << "WrongDog copy Constructor called" << std::endl;
}

WrongDog::~WrongDog() {
	std::cout << "WrongDog Destructor called" << std::endl;
}

WrongDog&	WrongDog::operator=(const WrongDog& other) {
	this->type = other.type;
	std::cout << "WrongDog copy assignment operator called" << std::endl;
	return (*this);
}

void	WrongDog::makeSound() const {
	std::cout << "WrongDog barks" << std::endl;
}