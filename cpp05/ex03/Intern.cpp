#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm   *Intern::MakeP(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm   *Intern::MakeR(std::string target) 
{
    return (new RobotomyRequestForm(target));
}

AForm   *Intern::MakeS(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

const char* Intern::invalid_name::what() const throw()
{
    return ("Invalid Form");
}

AForm   *Intern::makeForm(std::string form_name, std::string target)
{
    int     check;

    AForm * (Intern::*pts[3])(std::string) = {&Intern::MakeP, &Intern::MakeR, &Intern::MakeS};
	
    check = (form_name == "presidential pardon") + ( form_name == "robotomy request") * 2 + ( form_name == "shrubbery form") * 3 - 1 ;
    if (check == -1)
    {
        std::cerr << "[-] The form name not found." << std::endl;
        throw invalid_name();
    }
    std::cout << "Intern creates " << form_name << std::endl;
    return (this->*pts[check])(target);
}

Intern::Intern(const Intern& copy)
{
    (void)copy;
}

Intern &Intern::operator=(const Intern &eq)
{
    (void)eq;
    return (*this);
}

Intern::~Intern() {}

Intern::Intern() {}