#include "DiamondTrap.hpp"

// Default Constructor
DiamondTrap::DiamondTrap() : FragTrap(7), ScavTrap(7) {
	_name = "<DiamondTrap_anonymous>";
	ClapTrap::name = _name + "_clap_name";
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

// Paramether Constructor
DiamondTrap::DiamondTrap(const std::string& new_name) : FragTrap(7), ScavTrap(7) {
	_name = new_name;
	ClapTrap::name = _name + "_clap_name";

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
		std::cout << _name  << ", " << ClapTrap::name << std::endl;
}

// GETTERs
int	DiamondTrap::getAttack_damage() {
	return (attack_damage);
}

int	DiamondTrap::gethit_points() {
	return (hit_points);
}
int	DiamondTrap::getenergy_points() {
	return (energy_points);
}
