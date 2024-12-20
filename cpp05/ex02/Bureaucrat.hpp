#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
	const std::string	name;
	int					grade;

	public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat &operator=(const Bureaucrat &eq);
	~Bureaucrat();

	//GETTERS
	const std::string	getName() const;
	int					getGrade() const;

	void		inc_grade();
	void		dec_grade();
	void		signForm(AForm &form);

	//EXCEPTIONS
	class	GradeTooHighException : public std::exception
	{
		//we used throw to overide & do not throw an expection
		public:
		virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b);