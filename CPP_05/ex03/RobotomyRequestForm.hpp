#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

#define ROBOTOMYREQUEST_TOSIGN_GRADE 72
#define ROBOTOMYREQUEST_TOEXEC_GRADE 45

class RobotomyRequestForm : public AForm {
private:
	std::string	_target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm(const std::string& target);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	virtual void	execute(Bureaucrat const & executor) const;
	static AForm*	creator(const std::string& target);
};

#endif