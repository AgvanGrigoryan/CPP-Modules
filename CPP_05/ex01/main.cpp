#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void) {
//	Testing Form set too high sign grade
{
	std::cout << "\033[0;32m" << "Testing Form too high SIGN grade" << "\033[0m" << std::endl;
	try {
		Form form("Dolma declaration", -89, 10);
	}
	catch (Form::GradeTooHighException& e) {
		std::cout << "\033[0;031m" << "Form Sign Grade is too high!" << "\033[0m" << std::endl;
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << "\033[0;031m" << "Form Sign Grade is too low!" << "\033[0m" << std::endl;
	}
}
std::cout << '\n';

//	Testing Form set too low sign grade
{
	std::cout << "\033[0;32m" << "Testing Form set too low SIGN grade" << "\033[0m" << std::endl;
	try {
		Form form("Dolma declaration", 777, 10);
	}
	catch (Form::GradeTooHighException& e) {
		std::cout << "\033[0;031m" << "Form Sign Grade is too high!" << "\033[0m" << std::endl;
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << "\033[0;031m" << "Form Sign Grade is too low!" << "\033[0m" << std::endl;
	}
}
std::cout << '\n';

//	Testing Form set too high EXECUTE grade
{
	std::cout << "\033[0;32m" << "Testing Form too high EXECUTE grade" << "\033[0m" << std::endl;
	try {
		Form form("Dolma declaration", 10, -77);
	}
	catch (Form::GradeTooHighException& e) {
		std::cout << "\033[0;031m" << "Form Execute Grade is too high!" << "\033[0m" << std::endl;
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << "\033[0;031m" << "Form Execute Grade is too low!" << "\033[0m" << std::endl;
	}
}
std::cout << '\n';

//	Testing Form set too low EXECUTE grade
{
	std::cout << "\033[0;32m" << "Testing Form set too low EXECUTE grade" << "\033[0m" << std::endl;
	try {
		Form form("Dolma declaration", 10, 777);
	}
	catch (Form::GradeTooHighException& e) {
		std::cout << "\033[0;031m" << "Form Execute Grade is too high!" << "\033[0m" << std::endl;
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << "\033[0;031m" << "Form Execute Grade is too low!" << "\033[0m" << std::endl;
	}
}
std::cout << '\n';

// Bureaucrat grade not enough to sign the form
{
	std::cout << "\033[0;32m" << "Bureaucrat grade not enough to sign the form" << "\033[0m" << std::endl;

	Form form("Dolma declaration", 10, 1);
	Bureaucrat buro("Chaxo", 100);
	buro.signForm(form);
}
std::cout << '\n';

// Bureaucrat grade enough to sign the form
{
	std::cout << "\033[0;32m" << "Bureaucrat grade enough to sign the form" << "\033[0m" << std::endl;

	Form form("Dolma declaration", 10, 1);
	Bureaucrat buro("Chaxo", 5);
	buro.signForm(form);
}



}