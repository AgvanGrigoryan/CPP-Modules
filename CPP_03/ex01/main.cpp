#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	// ClapTrap claptrap("CLAPTRAP");
	ClapTrap* clp = new ScavTrap("POXOS");
	clp->attack("ohooho");
	// claptrap.attack("aaa");

	// ScavTrap scavtrap("SCAVTRAP");

	// scavtrap.attack("bbb");

}
