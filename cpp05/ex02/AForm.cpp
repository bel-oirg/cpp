#include "AForm.hpp"

AForm::AForm() : name("default"), is_signed(false), grade_sign(150), grade_exec(150) {}

AForm::AForm(const std::string name, int grade_sign, int grade_exec) : name(name), grade_sign(grade_sign), grade_exec(grade_exec)
{
    if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
    else if (grade_sign < 0 || grade_exec < 0)
        throw GradeTooHighException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &copy): name("default"), grade_sign(150), grade_exec(150)
{
    this->is_signed = copy.is_signed;
}

AForm &AForm::operator=(const AForm &eq)
{
    this->is_signed = eq.is_signed;
    return (*this);
}

std::ostream	&operator<<(std::ostream &o, AForm const &f)
{
	o << "the Aform name is " << f.getName()
	  << ", the grade to sign it is " << f.getGrade_sign()
	  << ", the grade to execute it is " << f.getGrade_exec();
	if (f.getIs_signed())
		o << ", this Aform is signed";
	else
		o << ", this Aform is not signed";
	return (o);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

std::string AForm::getName() const
{
	return (name);
}

int AForm::getGrade_sign() const
{
	return (grade_sign);
}

int AForm::getGrade_exec() const
{
	return (grade_exec);
}

bool AForm::getIs_signed() const
{
	return (is_signed);
}

void AForm::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() <= this->grade_sign)
	{
		std::cout << bur.getName() << " signed " << this->name << std::endl;
		this->is_signed = 1;
	}
	else
	{
		std::cerr << bur.getName() << " couldn't sign " << this->name << " because ";
		throw GradeTooLowException();
	}
}
