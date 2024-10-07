#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(10)
{
    // std::cout << "The defaut constuctor is called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 0)
        throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
//    std::cout << "The defaut destructor is called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
    // std::cout << "Copy constructor is called" << std::endl;
    this->grade = copy.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &eq)
{
    this->grade = eq.grade;
    return (*this);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

const std::string Bureaucrat::getName() const
{
    return (name);
}

void Bureaucrat::inc_grade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::dec_grade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

void    Bureaucrat::signForm(AForm &form)
{
    form.beSigned(*this);
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (o);
}

void    Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->name << " failed to execute " << form.getName() << std::endl;
        throw GradeTooLowException();
    }
}