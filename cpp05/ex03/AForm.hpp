#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
	const std::string   name;
	bool                is_signed;
	const int           grade_sign;
	const int           grade_exec;

	public:
	AForm(const std::string name, int grade_sign, int grade_exec);
	//ORTHDX
	AForm();
	virtual ~AForm(); // for a proper cleanup of the derived class
	AForm(const AForm &cpy);
	AForm &operator=(const AForm &eq);

	//GETTERS
	std::string			getName() const;
	int					getGrade_sign() const;
	int					getGrade_exec() const;
	bool				getIs_signed() const;

	void    beSigned(Bureaucrat &bur);
	//EXCEPTIONS
	class	GradeTooHighException : public std::exception
	{
		//we used throw() to overide & do not throw an exception
		public:
		virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, AForm const &f);