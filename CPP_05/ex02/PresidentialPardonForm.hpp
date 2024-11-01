#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"


#define PRESIDENTIAL_TOSIGN_GRADE 145
#define PRESIDENTIAL_TOEXEC_GRADE 137


class PresidentialPardonFrom : public AForm {
private:
	std::string	_target;

public:
	PresidentialPardonFrom();
	PresidentialPardonFrom(const PresidentialPardonFrom& other);
	PresidentialPardonFrom(const std::string& target);
	virtual ~PresidentialPardonFrom();

	PresidentialPardonFrom& operator=(const PresidentialPardonFrom& other);
	virtual void	execute(Bureaucrat const & executor) const;
};

#endif