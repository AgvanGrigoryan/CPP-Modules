#include "Zombie.hpp"

void	Zombie::announce(void) {
	std::cout <<  name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() : name("NoName") {};

void Zombie::setName(std::string& name) {
	this->name = name;
}

Zombie::~Zombie(void) {
	std::cout << "Destructor of " << name << std::endl;
}