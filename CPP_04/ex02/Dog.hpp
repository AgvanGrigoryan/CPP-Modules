#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain*	brain;

public:
	Dog();
	Dog(const Dog& other);
	virtual ~Dog();

	Dog&	operator=(const Dog& other);
	bool	setIdea(unsigned int idx, const std::string& idea);
	std::string	getIdea(unsigned int idx);
	void	makeSound() const;
};

#endif