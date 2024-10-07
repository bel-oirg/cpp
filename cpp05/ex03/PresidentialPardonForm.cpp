#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Pardon", 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm() : AForm("Pardon", 25, 5), target("unknown")
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
{
    *this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &eq)
{
    (void)eq;
    return (*this);
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIs_signed())
        throw FormNotSigned();
    if (executor.getGrade() > this->getGrade_exec()
    || executor.getGrade() > this->getGrade_sign())
        throw GradeTooLowException();
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const char* PresidentialPardonForm::FormNotSigned::what() const throw()
{
    return "The form is not signed";
}
