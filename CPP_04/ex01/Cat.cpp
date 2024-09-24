#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat default Constructor called" << std::endl;
}

Cat::Cat(const Cat& other){
	this->type = other.type;
	this->brain = new Brain(*other.brain);
	std::cout << "Cat copy Constructor called" << std::endl;
}

Cat::~Cat() {
	delete brain;
	brain = nullptr;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Сat meows" << std::endl;
}