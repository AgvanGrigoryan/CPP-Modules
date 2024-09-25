#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
	std::string		name;
	int				hit_points;
	int				energy_points;
	int				attack_damage;

public:
// constructors
	ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap(const std::string& name);
	~ClapTrap();

// overloaded operators
	ClapTrap& operator=(const ClapTrap& other); // copy assigment operator

// member functions
	virtual	void	attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};

#endif
