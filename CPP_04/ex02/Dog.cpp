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

bool	Dog::setIdea(unsigned int idx, const std::string& idea) {
	bool	result = brain->setIdea(idx, idea);
	if (result == false)
		std::cout << "\033[0;31m" << "setIdea: Index out of range(expected 0-100) or idea equal to \"INDEX_NOT_FOUND\"" << "\033[0m" << std::endl;
	return (result);
}

std::string	Dog::getIdea(unsigned int idx) {
	std::string result = brain->getIdea(idx);
	if (result == INVALID_IDX_RETURN_MSG)
		std::cout << "\033[0;31m" << "getIdea: Index out of range, expected 0-100" << "\033[0m" << std::endl;
	return (result);
}