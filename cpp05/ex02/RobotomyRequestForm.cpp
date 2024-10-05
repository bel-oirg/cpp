#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robot", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robot", 72, 45), target("unknown")
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
{
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &eq)
{
    (void)eq;
    return (*this);
}