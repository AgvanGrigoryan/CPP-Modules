#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
protected:
	FragTrap(int);
public:
	FragTrap();
	FragTrap(const std::string& name);
	virtual ~FragTrap();

	virtual void	attack(const std::string& target);
	void	highFivesGuys(void);
	
};


#endif