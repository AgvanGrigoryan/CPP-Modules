#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < IDEAS_CNT; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this == &other)
		return (*this);

	for (int i = 0; i < IDEAS_CNT; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << "Brain copy assignment operator called" << std::endl;
	return (*this);
}

bool	Brain::setIdea(unsigned int idx, const std::string& idea) {
	if (idx < 0 || idx > IDEAS_CNT || idea == INVALID_IDX_RETURN_MSG)
		return (false);
	ideas[idx] = idea;
	return (true);
}

std::string	Brain::getIdea(unsigned int idx) {
	if (idx < 0 || idx > IDEAS_CNT)
		return (INVALID_IDX_RETURN_MSG);
	return (ideas[idx]);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
