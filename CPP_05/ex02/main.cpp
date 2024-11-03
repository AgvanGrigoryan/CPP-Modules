#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void) {
	srand(time(0));
	// Testing ShrubberyCreationForm execution without signing
	{
		std::cout << "\033[0;32m" << "Testing ShrubberyCreationForm execution without signing" << "\033[0m" << std::endl;
		ShrubberyCreationForm form("Garden");
		Bureaucrat bob("Bob", 140); // Sufficient grade for execution if signed
		try {
			bob.executeForm(form); // Should throw FormNotSignedException
		}
		catch (const AForm::FormNotSignedException& e) {
			std::cout << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
		}
	}
	std::cout << '\n';

	// Testing RobotomyRequestForm execution with insufficient grade
	{
		std::cout << "\033[0;32m" << "Testing RobotomyRequestForm execution with insufficient grade" << "\033[0m" << std::endl;
		RobotomyRequestForm form("Bender");
		Bureaucrat bob("Bob", 70); // Insufficient grade for execution
		bob.signForm(form);
		try {
			bob.executeForm(form); // Should throw InsufficientGradeException
		}
		catch (const AForm::InsufficientGradeException& e) {
			std::cout << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
		}
	}
	std::cout << '\n';

	// Testing PresidentialPardonForm execution with sufficient grade
	{
		std::cout << "\033[0;32m" << "Testing PresidentialPardonForm execution with sufficient grade" << "\033[0m" << std::endl;
		PresidentialPardonForm form("Arthur Dent");
		Bureaucrat zaphod("Zaphod", 1); // High grade, sufficient for execution
		zaphod.signForm(form);
		try {
			zaphod.executeForm(form); // Should succeed
		}
		catch (const std::exception& e) {
			std::cout << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
		}
	}
	std::cout << '\n';

	// Testing ShrubberyCreationForm successful execution
	{
		std::cout << "\033[0;32m" << "Testing ShrubberyCreationForm successful execution" << "\033[0m" << std::endl;
		ShrubberyCreationForm form("Park");
		Bureaucrat alice("Alice", 137); // Sufficient grade for signing and execution
		form.beSigned(alice);
		try {
			alice.executeForm(form); // Should succeed and create a file with ASCII art
		}
		catch (const std::exception& e) {
			std::cout << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
		}
	}
	std::cout << '\n';

	// Testing RobotomyRequestForm with random success/failure outcome
	{
		std::cout << "\033[0;32m" << "Testing RobotomyRequestForm with random success/failure outcome" << "\033[0m" << std::endl;
		RobotomyRequestForm form("Marvin");
		Bureaucrat ford("Ford", 45); // Sufficient grade for execution
		form.beSigned(ford);
		try {
			ford.executeForm(form); // Randomly succeeds or fails
		}
		catch (const std::exception& e) {
			std::cout << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
		}
	}
	std::cout << '\n';
	return (0);
}
