#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    {
        std::cout << "\033[0;32m" << "Testing successful form creation (RobotomyRequestForm)" << "\033[0m" << std::endl;
        Intern intern;
        try {
            AForm* form = intern.makeForm("robotomy request", "Bender");
            delete form;  // Не забудьте освободить память
        }
        catch (Intern::FormNotFoundException& e) {
            std::cout << "\033[0;031m" << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << '\n';

    {
        std::cout << "\033[0;32m" << "Testing successful form creation (ShrubberyCreationForm)" << "\033[0m" << std::endl;
        Intern intern;
        try {
            AForm* form = intern.makeForm("shrubbery creation", "Garden");
            delete form;  // Освободите память
        }
        catch (Intern::FormNotFoundException& e) {
            std::cout << "\033[0;031m" << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << '\n';

    {
        std::cout << "\033[0;32m" << "Testing successful form creation (PresidentialPardonForm)" << "\033[0m" << std::endl;
        Intern intern;
        try {
            AForm* form = intern.makeForm("presidential pardon", "Arthur Dent");
            delete form;  // Освободите память
        }
        catch (Intern::FormNotFoundException& e) {
            std::cout << "\033[0;031m" << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << '\n';

    {
        std::cout << "\033[0;32m" << "Testing form creation with invalid form name" << "\033[0m" << std::endl;
        Intern intern;
        try {
            AForm* form = intern.makeForm("invalid form", "Test Target");
            delete form;  // Не забудьте освободить память
        }
        catch (Intern::FormNotFoundException& e) {
            std::cout << "\033[0;031m" << e.what() << "\033[0m" << std::endl;
        }
    }
    return 0;
}