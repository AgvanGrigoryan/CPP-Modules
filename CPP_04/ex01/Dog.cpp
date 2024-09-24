#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() {
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog default Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
	this->type = other.type;
	this->brain = new Brain(*other.brain);
	std::cout << "Dog copy Constructor called" << std::endl;
}

Dog::~Dog() {
	delete brain;
	brain = NULL;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Dog barks" << std::endl;
}