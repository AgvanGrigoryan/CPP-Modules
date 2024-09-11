#include <iostream>
#include "Zombie.hpp"

int	main(void) {
	int	numberOfZombies(5);
	Zombie* hordeOfZombies = zombieHorde(numberOfZombies, "EnderMan");

	if (hordeOfZombies == NULL)
		return (1);
	for (int i = 0; i < numberOfZombies; i++) {
		hordeOfZombies[i].announce();
	}
	delete[] hordeOfZombies;
	return (0);
}