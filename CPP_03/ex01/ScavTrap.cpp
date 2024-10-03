#include "ScavTrap.hpp"

// Default Constructor
ScavTrap::ScavTrap() {
	name = "<ScavTrap_anonymous>";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Paramether Constructor
ScavTrap::ScavTrap(const std::string& new_name) {
	name = new_name;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap parameter constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (hit_points <= 0 || energy_points <= 0) {
		std::cout << name << " doesn't have enough energy or hit points to attack " << target << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void	ScavTrap::guardGate() {
	std::cout << name << "ScavTrap is now in Gate keeper mode" << std::endl;
}