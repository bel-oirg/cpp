#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robot", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robot", 72, 45), target("unknown")
{}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
{
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &eq)
{
    this->target = eq.target;
    return (*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIs_signed())
        throw FormNotSigned();
    if (executor.getGrade() > this->getGrade_exec()
    || executor.getGrade() > this->getGrade_sign())
        throw GradeTooLowException();
    std::cout << "[!] Drilling Noise [!]" << std::endl;
    
    srand(time(NULL));
    if (rand() % 2)
        std::cout << this->target << " has been robotomized successfully" << std::endl; 
    else
        std::cout << "The robotomy of " << target << " failed." << std::endl;
}

const char* RobotomyRequestForm::FormNotSigned::what() const throw()
{
    return "The form is not signed";
}
