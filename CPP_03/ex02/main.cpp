#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap clap1("Boyo");
	FragTrap clap2("Lolo");

	// testing attack
	std::cout << "\033[1;32m\n" << "Testing attack" << "\033[0m" << std::endl;
	clap1.attack("Bruce Lee");
	std::cout << "\033[0;33m" << "ScavTrap will print different attack message" << "\033[0m" << std::endl;
	clap2.attack("Boyo");

	// testing takeDamage
	std::cout << "\033[1;32m\n" << "testing takeDamage" << "\033[0m" << std::endl;
	clap2.takeDamage(7);

	// testing beRepaired
	std::cout << "\033[1;32m\n" << "testing Repair" << "\033[0m" << std::endl;
	clap2.beRepaired(20);

	// testing GuardGate
	std::cout << "\033[1;32m\n" << "testing GuardGate" << "\033[0m" << std::endl;
	clap2.highFivesGuys();

	std::cout << "\033[1;34m\n" << "Destructors" << "\033[0m" << std::endl;
}
