#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm   *Intern::makeForm(std::string form_name, std::string target)
{
    int     check;
    AForm   *arr[3];
    int     index;

    arr[0] = new PresidentialPardonForm(target);
    arr[1] = new RobotomyRequestForm(target);
    arr[2] = new ShrubberyCreationForm(target);

    check = (form_name == "presidential pardon") + ( form_name == "robotomy request") * 2 + ( form_name == "shrubbery form") * 3 - 1 ;
    index = 0;
    while(index < 3 && index != check)
        index++;
    if (index >= 3)
    {
        index = -1;
        while(++index < 3)
            delete arr[index];
        std::cerr << "[-] The form name not found." << std::endl;
        return (NULL);
    }
    index = -1;
    while (++index < 3)
    {
        if (index != check)
            delete arr[index];
    }
    return arr[check];
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