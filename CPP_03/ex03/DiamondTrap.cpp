#include "DiamondTrap.hpp"

// Default Constructor
DiamondTrap::DiamondTrap() {
	name = "<DiamondTrap_anonymous>";
	ClapTrap::name = name + "_clap_name";
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::hit_points;
	attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

// Paramether Constructor
DiamondTrap::DiamondTrap(const std::string& new_name) {
	name = new_name;
	ClapTrap::name = name + "_clap_name";
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::hit_points;
	attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap parameter constructor called" << std::endl;
};

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) {
	if (this == &other) return;

	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;

	std::cout << "Copy Constructor called" << std::endl;
}

// Copy assigment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this == &other) return (*this);

	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;

	std::cout << "Copy assigment operator called" << std::endl;
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
		std::cout << name  << ", " << ClapTrap::name << std::endl;
}