#include <iostream>
#include <climits>
#include "ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap() : name("<anonymous>"), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

// Paramether Constructor
ClapTrap::ClapTrap(const std::string& new_name) : name(new_name), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap Parameter Constructor called" << std::endl;
};

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) {
	if (this == &other) return;

	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;

	std::cout << "ClapTrap Copy Constructor called" << std::endl;
}

// Copy assigment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this == &other) return (*this);

	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;

	std::cout << "ClapTrap Copy assigment operator called" << std::endl;
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

// Member functions
void ClapTrap::attack(const std::string& target) {
	if (hit_points <= 0 || energy_points <= 0) {
		std::cout << name << " doesn't have enough energy or hit points to attack " << target << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hit_points <= 0)
		return ;
	std::cout << name << " takes " << amount << " damage" << std::endl;
	if (amount >= static_cast<unsigned int>(hit_points))
	{
		hit_points = 0;
		std::cout << name << " die" << std::endl;
	}
	else
		hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	long long int	tmp;
	if (hit_points <= 0 || energy_points <= 0) {
		std::cout << "Not enough energy or hit points to repair" << std::endl;
		return ;
	}
	tmp = hit_points + amount;
	if (tmp > INT_MAX)
		hit_points = INT_MAX;
	else
		hit_points += amount;
	energy_points--;
	std::cout << name << " repaired " << amount << " hit points" << std::endl;
}
