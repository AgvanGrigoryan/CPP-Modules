#include "Zombie.hpp"

void	Zombie::announce(void) {
	std::cout <<  name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() : name("NoName") {};

Zombie::Zombie(std::string& name) {
	this->name = name;
}

Zombie::~Zombie(void) {
	std::cout << name << std::endl;
}