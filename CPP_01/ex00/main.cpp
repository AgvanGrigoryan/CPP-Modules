#include <iostream>

#include "Zombie.hpp"

int	main(void) {
	Zombie* some_zombie = newZombie("EnderMan");

	some_zombie->announce();
	delete some_zombie;

	randomChump("WhoIAm");
	return (0);
}