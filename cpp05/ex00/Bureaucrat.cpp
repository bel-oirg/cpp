#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(10)
{
    std::cout << "The defaut constuctor is called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
       std::cout << "The defaut destructor is called" << std::endl;
}

int Bureaucrat::getGrade()
{
    return (grade);
}

const std::string Bureaucrat::getName()
{
    return (name);
}

void    Bureaucrat::inc_grade()
{
    if (grade >= 150)
        throw GradeTooHighException();
    grade++;
}

void    Bureaucrat::dec_grade()
{
    if (grade <= 1)
        throw GradeTooLowException();
    grade--;
}

class Bureaucrat::GradeTooHighException : public std::exception
{
    const char *what() const noexcept override
    {
        return "Grade Too High";
    }
};

class Bureaucrat::GradeTooLowException : public std::exception
{
    const char *what() const noexcept override
    {
        return "Grade Too Low";
    }
};