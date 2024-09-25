#ifndef DIAMONGTRAP_HPP
#define DIAMONGTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string	_name;

public:
// constructors
	DiamondTrap();
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap(const std::string& name);
	~DiamondTrap();

// overloaded operators
	DiamondTrap& operator=(const DiamondTrap& other); // copy assigment operator

	using	ScavTrap::attack;
	void	whoAmI(void);
	int		getAttack_damage();
	int		getenergy_points();
	int		gethit_points();
};

#endif