#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat default Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
	this->type = other.type;
	std::cout << "WrongCat copy Constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	this->type = other.type;
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "WrongСat meows" << std::endl;
}