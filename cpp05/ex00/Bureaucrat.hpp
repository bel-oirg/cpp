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
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat &operator=(const Bureaucrat &eq);
	Bureaucrat();
	~Bureaucrat();
	const std::string getName() const;
	int			getGrade() const;
	void		inc_grade();
	void		dec_grade();

	class	GradeTooHighException : public std::exception
	{
		public:
		const char* what() const throw();
	};
	
	class	GradeTooLowException : public std::exception
	{
		public:
		const char* what() const throw();
	};
};
