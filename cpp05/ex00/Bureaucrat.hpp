#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
	const std::string	name;
	int					grade;

	Bureaucrat();
	
	~Bureaucrat();

	public:
	const std::string getName();
	void		inc_grade();
	void		dec_grade();
	int			getGrade();
	class		GradeTooHighException;
	class		GradeTooLowException;
};

/*
	try
	{
	
	}
	catch (int param)
	{
		std::cout << |shit << std::endl;
	}
	catch (...) //default exception
	{
	
	}

	exception is a base class
	of many exception class
	(bad_alloc, logic err,  out_of_range ..)
	exception has a method called what
	e.what();
*/