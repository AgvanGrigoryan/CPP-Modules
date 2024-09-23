#include "ScavTrap.hpp"

// Default Constructor
ScavTrap::ScavTrap() {
	name = "<ScavTrap_anonymous>";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

// Paramether Constructor
ScavTrap::ScavTrap(const std::string& new_name) {
	name = new_name;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap parameter constructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (energy_points <= 0) {
		std::cout << "Not enough energy points to attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void	ScavTrap::guardGate() {
	std::cout << name << "ScavTrap is now in Gate keeper mode" << std::cout;
}