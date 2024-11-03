#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

#define PRESIDENTIAL_TOSIGN_GRADE 25
#define PRESIDENTIAL_TOEXEC_GRADE 5

class PresidentialPardonForm : public AForm {
private:
	std::string	_target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm(const std::string& target);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	virtual void	execute(Bureaucrat const & executor) const;
};

#endif