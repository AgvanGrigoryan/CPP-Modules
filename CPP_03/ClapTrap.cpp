#include <iostream>
#include "ClapTrap.hpp"
/*
private:
        std::string     name;
        int             hit_points;
        int             energy_points;
        int             attack_damage;

public:
// constructors
        ClapTrap();
        ClapTrap(ClapTrap& other);
        ClapTrap(std::string& name);
        ~ClapTrap();

// overloaded operators
        Fixed& operator=(ClapTrap& other); // copy assigment operator

// member functions
        void    attack(const std::stirng& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
*/
// Default Constructor
ClapTrap::ClapTrap() : hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "Default Constructor called" << std::endl;
}

// Paramether Constructor
ClapTrap::ClapTrap(const std::string& new_name) : name(new_name), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "Parameter Constructor called" << std::endl;
};

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) {
	if (this == &other) return;

	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;

	std::cout << "Copy Constructor called" << std::endl;
}

// Copy assigment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this == &other) return (*this);

	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;

	std::cout << "Copy assigment operator called" << std::endl;
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap() {
	name.clear();

	std::cout << "Destructor called" << std::endl;
}

// Member functions
void ClapTrap::attack(const std::string& target) {
	if (energy_points <= 0)	return ;
	std::cout << "ClapTrap " << name << "attacks " << target << ", causing " << attack_damage << "points of damage!";
	energy_points--;
}
/*
void ClapTrap::takeDamage(unsigned int amount) {
	
}
*/
void ClapTrap::beRepaired(unsigned int amount) {
	if (energy_points <= 0)
		return ;
	hit_points += amount;
	energy_points--;
}
