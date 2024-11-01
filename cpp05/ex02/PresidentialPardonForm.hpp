#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
	std::string   target;

    public:
	PresidentialPardonForm(std::string target);
	//ORTHDX
	PresidentialPardonForm(); //TODO All of them take only one parameter in their constructor:
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