#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int	main(void)
{
	// ClapTrap claptrap("CLAPTRAP");
	FragTrap* clp = new FragTrap("POXOS");
	clp->attack("ohooho");
	// claptrap.attack("aaa");

	// ScavTrap scavtrap("SCAVTRAP");

	// scavtrap.attack("bbb");

}
