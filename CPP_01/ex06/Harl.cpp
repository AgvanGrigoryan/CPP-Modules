#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int		Harl::getLevelCode(std::string& level)
{
	std::string	levels[4] = {"INFO", "DEBUG", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			return (i);
	}
	return (-1);
}
void	Harl::filter(std::string level)
{
	void	(Harl::*functions[4]) () = { &Harl::info, &Harl::debug, &Harl::warning, &Harl::error};
	int	levelCode = getLevelCode(level);

	switch (levelCode)
	{
		case 0:
			(this->*functions[0])();
			// fall through
		case 1:
			(this->*functions[1])();
			// fall through
		case 2:
			(this->*functions[2])();
			// fall through
		case 3:
			(this->*functions[3])();
			break;
		default:
			std::cout << "[ I am not sure how tired I am today... ]" << std::endl;
			break;
	}


}
