#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
	private:
	const std::string	name;
	int					grade;

	public:
	Bureaucrat(const std::string name, int grade);
	//ORTHDX
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat &operator=(const Bureaucrat &eq);
	Bureaucrat();
	~Bureaucrat();

	//GETTERS
	const std::string	getName() const;
	int					getGrade() const;

	void		inc_grade();
	void		dec_grade();
	void		signForm(Form &form);

	//EXCEPTIONS
	class	GradeTooHighException : public std::exception
	{
		//we used throw to overide & do not throw an expection
		public:
		const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
		const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b);