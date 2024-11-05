#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Robot", 145, 137), target("unknown")
{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &eq)
{
    this->target = eq.target;
    return (*this);
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIs_signed())
        throw FormNotSigned();
    if (executor.getGrade() > this->getGrade_exec()
    || executor.getGrade() > this->getGrade_sign())
        throw GradeTooLowException();
    std::ofstream myfile(target + "_shrubbery");
    if (!myfile.is_open())
    {
        std::cout << "[-] Unable to open the file" << std::endl;
        return ;
    }
    myfile << "               ,@@@@@@@,\n";
    myfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    myfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
    myfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/888\n";
    myfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\888888\n";
    myfile << "   %&&%/ %&%%&&@@\\ V /@@8 888\\8 8/888\n";
    myfile << "   8&%\\ 8 /%&8    |.|        \\ 8|88\n";
    myfile << "       |o|        | |         | |\n";
    myfile << "       |.|        | |         | |\n";
    myfile << "    \\\\ / ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
    myfile.close();
}

const char* ShrubberyCreationForm::FormNotSigned::what() const throw()
{
    return "The form is not signed";
}
