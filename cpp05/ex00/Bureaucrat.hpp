#pragma once

#include <iostream>
#include <string>
#include <exception>

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

	//highest means Grade < 1
	class	GradeTooHighException : public std::exception
	{
		//we used throw to overide & do not throw an expection
		public:
		virtual const char* what() const throw();
	};
	
	//lowest means Grade > 150
	class	GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b);