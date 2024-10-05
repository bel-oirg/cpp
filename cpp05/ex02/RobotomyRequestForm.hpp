#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
	std::string   target;

	RobotomyRequestForm();

    public:
	RobotomyRequestForm(std::string target);
	//ORTHDX
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &cpy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &eq);

    void execute(Bureaucrat const &executor) const;
};