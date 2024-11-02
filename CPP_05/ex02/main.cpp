#include "Bureaucrat.hpp"

#include <iostream>
#include "ShrubberyCreationForm.hpp"

int	main(void) {

// Bureaucrat grade enough to sign the form
{
	std::cout << "\033[0;32m" << "Bureaucrat grade enough to sign the form" << "\033[0m" << std::endl;

	ShrubberyCreationForm form("Home");
	Bureaucrat buro("Chaxo", 180);
	buro.signForm(form);
	std::cout << "\n";
	form.execute(buro);
}
	return (0);
}
