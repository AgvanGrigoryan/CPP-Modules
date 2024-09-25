#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
protected:
	ScavTrap(int);
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	virtual ~ScavTrap();

	virtual void	attack(const std::string& target);
	void	guardGate();
	
};


#endif