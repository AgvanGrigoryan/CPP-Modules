#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap dt("POXOS");

	// testing attack
	std::cout << "\033[1;32m\n" << "Testing attack (attack of ScavTrap should be called)" << "\033[0m" << std::endl;
	dt.attack("gggg");

	// print current values of Diamond trap members
	std::cout << "\033[1;32m\n" << "Current values" << "\033[0m" << std::endl;
	std::cout << "Attack: " << dt.getAttack_damage() << std::endl;
	std::cout << "Energy: " << dt.getenergy_points() << std::endl;
	std::cout << "Hit: " << dt.gethit_points() << std::endl;

	// Testing whoAmI
	std::cout << "\033[1;32m\n" << "testing whoAmI" << "\033[0m" << std::endl;
	dt.whoAmI();

	std::cout << "\033[1;34m\n" << "Destructors" << "\033[0m" << std::endl;
	return (0);
}
