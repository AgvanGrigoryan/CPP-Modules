#include "Bureaucrat.hpp"
#include <iostream>

int	main(void) {
//	Testing bureaucrat set negative grade
{
	std::cout << "\033[0;32m" << "Testing bureaucrat set negative grade" << "\033[0m" << std::endl;
	try {
		Bureaucrat ponch("Armenchik", -89);
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "\033[0;031m" << "New Grade is too high!" << "\033[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "\033[0;031m" << "New Grade is too low!" << "\033[0m" << std::endl;
	}
}
std::cout << '\n';

//	Testing bureaucrat set too high grade
{
	std::cout << "\033[0;32m" << "Testing bureaucrat set too high grade" << "\033[0m" << std::endl;
	try {
		Bureaucrat ponch("Armenchik", 777);
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "\033[0;031m" << "New Grade is too high!" << "\033[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "\033[0;031m" << "New Grade is too low!" << "\033[0m" << std::endl;
	}
}
std::cout << '\n';

//	Testing bureaucrat grade incrementing
{
	std::cout << "\033[0;32m" << "Testing bureaucrat grade incrementing" << "\033[0m" << std::endl;
	Bureaucrat ponch("Armenchik", 2);
	try {
		std::cout << ponch << std::endl;
		ponch.raiseGrade();
		std::cout << ponch << std::endl;
		ponch.raiseGrade();
		std::cout << ponch << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "\033[0;031m" << "New Grade is too high!" << "\033[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "\033[0;031m" << "New Grade is too low!" << "\033[0m" << std::endl;
	}
}
std::cout << '\n';

//	Testing bureaucrat grade DEcrementing
{
	std::cout << "\033[0;32m" << "Testing bureaucrat grade DEcrementing" << "\033[0m" << std::endl;
	Bureaucrat ponch("Armenchik", 149);
	try {
		std::cout << ponch << std::endl;
		ponch.downGrade();
		std::cout << ponch << std::endl;
		ponch.downGrade();
		std::cout << ponch << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "\033[0;031m" << "New Grade is too high!" << "\033[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "\033[0;031m" << "New Grade is too low!" << "\033[0m" << std::endl;
	}
}
std::cout << '\n';

//	Testing bureaucrat normal grade
{
	std::cout << "\033[0;32m" << "Testing bureaucrat normal grade" << "\033[0m" << std::endl;
	try {
		Bureaucrat ponch("Armenchik", 75);
		std::cout << ponch << std::endl;
		ponch.downGrade();
		std::cout << ponch << std::endl;
		ponch.raiseGrade();
		std::cout << ponch << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "\033[0;031m" << "New Grade is too high!" << "\033[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "\033[0;031m" << "New Grade is too low!" << "\033[0m" << std::endl;
	}
}
}