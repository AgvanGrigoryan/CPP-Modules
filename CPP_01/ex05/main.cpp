#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		Harl	harl;
		harl.complain(argv[1]);
		return (0);
	}
	std::cout << "Expected one argument" << std::endl;
	return (1);
}

// void	test_level(Harl& harl, const std::string& level)
// {
// 	std::cout << "\033[1;32m" << level << "\033[0m" << std::endl;;
// 	harl.complain(level);
// }

// int	main(void)
// {
// 	Harl harl;

// 	test_level(harl, "DEBUG");
// 	test_level(harl, "INFO");
// 	test_level(harl, "WARNING");
// 	test_level(harl, "ERROR");

// }