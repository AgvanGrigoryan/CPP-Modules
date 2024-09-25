#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap1("Boyo");
	ClapTrap clap2;

	// testing attack
	std::cout << "\033[1;32m\n" << "Testing attack" << "\033[0m" << std::endl;
	clap1.attack("Bruce Lee");
	clap2.attack("Boyo");

	// testing takeDamage
	std::cout << "\033[1;32m\n" << "testing takeDamage" << "\033[0m" << std::endl;
	clap1.takeDamage(7);
	clap1.takeDamage(5); // Boyo should die :(

	// testing beRepaired
	std::cout << "\033[1;32m\n" << "testing Repair" << "\033[0m" << std::endl;
	clap2.beRepaired(2);
	clap2.takeDamage(50);
	std::cout << "\033[1;33m\n" << "Shouldn't repair since hit points are 0" << "\033[0m" << std::endl;
	clap2.beRepaired(10); // Shouldn't repair since hit points are 0

	ClapTrap clap3("Anushik");
	for (int i = 0; i < 10; i++)
		clap3.attack("Sweet shop");

	// Shouln't attack because no enough energy
	std::cout << "\033[1;33m\n" << "11th attack to Sweet shop" << "\033[0m" << std::endl;
	clap3.attack("Sweet shop");
	
	std::cout << "\033[1;34m\n" << "Destructors" << "\033[0m" << std::endl;
}
