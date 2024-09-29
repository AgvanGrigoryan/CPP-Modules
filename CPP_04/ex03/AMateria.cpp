#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& type) {
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::AMateria(std::string const & new_type) : type(new_type) {
	std::cout << "AMateria parameter constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::operator=(const AMateria& other) {
	if (*this != other)
		type = other->type;
	std::cout << "AMateria copy assignment operator called" << std::endl;
}

std::string const & AMateria::getType() const {
	return (type);
}

void AMateria::use(ICharacter& target) {

}
