#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
	std::string   target;
	ShrubberyCreationForm();

    public:
	ShrubberyCreationForm(std::string target);
	//ORTHDX
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &eq);

	class	FormNotSigned : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
    void execute(Bureaucrat const &executor) const;
};