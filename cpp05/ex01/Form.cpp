#include "Form.hpp"

std::ostream	&operator<<(std::ostream &o, Form const &f)
{
	o << "the form name is " << f.getName()
	  << ", the grade to sign it is " << f.getGrade_sign()
	  << ", the grade to execute it is " << f.getGrade_exec();
	if (f.getIs_signed())
		o << ", this form is signed";
	else
		o << ", this form is not signed";
	return (o);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

int Form::getGrade_sign() const
{
	return (grade_sign);
}

int Form::getGrade_exec() const
{
	return (grade_exec);
}

bool Form::getIs_signed() const
{
	return (is_signed);
}

const std::string Bureaucrat::getName() const
{
	return (name);
}

void Form::beSigned(Bureaucrat bur)
{
	if (bur.getGrade() <= this->grade_sign)
	{
		std::cout << bur.getName() << " signed " << this->name << std::endl;
		this->is_signed = 1;
	}
	else
	{
		std::cout << bur.getName() << " couldn't sign " << this->name << " because ";
		throw GradeTooLowException();
	}
}
