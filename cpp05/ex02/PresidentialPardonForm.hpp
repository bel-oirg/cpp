#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
	std::string   target;
	PresidentialPardonForm();

    public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &cpy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &eq);

	class	FormNotSigned : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
    void execute(Bureaucrat const &executor) const;
};