#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
	const std::string   name;
	bool                is_signed;
	const int           grade_sign;
	const int           grade_exec;

	public:
	Form(const std::string name, int grade_sign, int grade_exec);
	//ORTHDX
	Form();
	~Form();
	Form(const Form &cpy);
	Form &operator=(const Form &eq);

	//GETTERS
	std::string			getName() const;
	int					getGrade_sign() const;
	int					getGrade_exec() const;
	bool				getIs_signed() const;

	void    beSigned(Bureaucrat &bur);
	//EXCEPTIONS
	class	GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form const &f);
