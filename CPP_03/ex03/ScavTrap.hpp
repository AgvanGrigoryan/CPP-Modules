#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap();
	ScavTrap(int); // special constructor for diamondTrap
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	virtual ~ScavTrap();

	ScavTrap& operator=(const ScavTrap& other);
	void	attack(const std::string& target);
	void			guardGate();
	
};


#endif