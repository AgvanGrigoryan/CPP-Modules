#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
private:
	std::string		name;
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;

public:
// constructors
	virtual ClapTrap();
	virtual ClapTrap(const ClapTrap& other);
	virtual ClapTrap(const std::string& name);
	virtual ~ClapTrap();

// overloaded operators
	ClapTrap& operator=(const ClapTrap& other); // copy assigment operator

// member functions
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
