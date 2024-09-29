#include "Caracter.hpp"

CHaracter::Character() : name("noname") {
	std::cout << "Character Default constructor called" << std::endl;
}

CHaracter::Character(const Character& other) : name(other.name) {
	std::cout << "Character Copy constructor called" << std::endl;
}

virtual CHaracter::~Character() {
	std::cout << "Character Destructor called" << std::endl;
}

CHaracter::operator=(const Character& other) {
	if (*this != other)
		name = other.name;
	std::cout << "Character copy assignment operator called" << std::endl;
}

std::string const & getName() const {
	return (name);
}

void equip(AMateria* m) {

}

void unequip(int idx) {

}

void use(int idx, ICharacter& target) {

}
