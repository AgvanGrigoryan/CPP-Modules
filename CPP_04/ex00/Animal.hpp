#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
	std::string	type;

public:
	Animal();
	Animal(Animal& other);
	~Animal();


	Animal	operator=(Animal& other);
	void	makeSound();
}

#endif