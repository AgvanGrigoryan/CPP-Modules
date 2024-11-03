#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void) {
	srand(time(0));
	// Bureaucrat grade enough to sign the form
	{
		std::cout << "\033[0;32m" << "Bureaucrat grade enough to sign the form" << "\033[0m" << std::endl;

		ShrubberyCreationForm form("Home");
		Bureaucrat buro("Chaxo", 100);
		buro.signForm(form);
		std::cout << "\n";
		form.execute(buro);
	}
	return (0);
}
