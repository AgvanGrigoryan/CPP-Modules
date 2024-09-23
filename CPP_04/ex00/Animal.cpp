#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal Constructor called" std::endl;
}

Animal::Animal(Animal& other) {
	this->type = other.type;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" std::endl;
}



Animal	Animal::operator=(Animal& other) {
	this->type = other.type;
}

void	Animal::makeSound() {
	std::cout << "Animal make some sound" << std::endl;
}
