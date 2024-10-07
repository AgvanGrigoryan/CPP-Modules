#include "Bureaucrat.hpp"
#include <iostream>


int	main(void) {
	Bureaucrat* ponch = NULL;

	try {
		ponch = new Bureaucrat("Armenchik", 2);
		ponch->raiseGrade();
		ponch->raiseGrade();
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "\033[0;031m" << "New Grade is too high!" << "\033[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "\033[0;031m" << "New Grade is too low!" << "\033[0m" << std::endl;
	}

	if (ponch != NULL)
		std::cout << *ponch << std::endl;
	delete ponch;
}