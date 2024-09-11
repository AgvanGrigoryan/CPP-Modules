#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		Harl	harl;
		harl.filter(argv[1]);
		return (0);
	}
	std::cout << "Expected one argument" << std::endl;

}