#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	int		getLevelCode(std::string& level);
public:
	void	filter(std::string level);
};

#endif