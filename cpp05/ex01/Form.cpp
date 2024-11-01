#include "Form.hpp"

Form::Form() : name("default"), is_signed(false), grade_sign(150), grade_exec(150)
{
    // std::cout << "The defaut constuctor is called" << std::endl;
}

Form::Form(const std::string name, int grade_sign, int grade_exec) : name(name), is_signed(false), grade_sign(grade_sign), grade_exec(grade_exec)
{
    if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
    else if (grade_sign < 0 || grade_exec < 0)
        throw GradeTooHighException();
}

Form::~Form()
{
//    std::cout << "The default destructor is called" << std::endl;
}

Form::Form(const Form &copy): name(copy.getName()), is_signed(false), grade_sign(copy.getGrade_sign()), grade_exec(copy.getGrade_exec())
{
    // std::cout << "Copy constructor is called" << std::endl;
}

Form &Form::operator=(const Form &eq)
{
    this->is_signed = eq.is_signed;
    return (*this);
}

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

std::string Form::getName() const
{
	return (name);
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

void Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() <= this->grade_sign)
		this->is_signed = 1;
	else
		throw GradeTooLowException();
}
