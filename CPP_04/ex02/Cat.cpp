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

bool	Cat::setIdea(unsigned int idx, const std::string& idea) {
	bool	result = brain->setIdea(idx, idea);
	if (result == false)
		std::cout << "\033[0;31m" << "setIdea: Index out of range(expected 0-100) or idea equal to \"INDEX_NOT_FOUND\"" << "\033[0m" << std::endl;
	return (result);
}

std::string	Cat::getIdea(unsigned int idx) {
	std::string result = brain->getIdea(idx);
	if (result == INVALID_IDX_RETURN_MSG)
		std::cout << "\033[0;31m" << "getIdea: Index out of range, expected 0-100" << "\033[0m" << std::endl;
	return (result);
}