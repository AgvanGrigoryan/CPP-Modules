#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

#define SHRUBBERY_TOSIGN_GRADE 145
#define SHRUBBERY_TOEXEC_GRADE 137

class ShrubberyCreationForm : public AForm {
private:
	std::string	_target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm(const std::string& target);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	virtual void	execute(Bureaucrat const & executor) const;
	static AForm*	creator(const std::string& target);
};

#endif