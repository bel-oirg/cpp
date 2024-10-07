#pragma once

#include "AForm.hpp"
#include <time.h>

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

	class	FormNotSigned : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
    void execute(Bureaucrat const &executor) const;
};