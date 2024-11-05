#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"


int main()
{
    std::cout << "-----A-----" << std::endl;
    try
    {
        Bureaucrat b("the bur", 2);
        ShrubberyCreationForm ff("TREE");
        ff.beSigned(b);
        b.executeForm(ff);
        ff.execute(b);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-----B-----" << std::endl;
    try
    {
        Bureaucrat b("the bur", 2);
        RobotomyRequestForm f("nameOFFORM");
        f.beSigned(b);
        f.execute(b);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-----C-----" << std::endl;
    try
    {
        Bureaucrat b("the bur", 1);
        PresidentialPardonForm f("nameOFFORM");
        f.beSigned(b);
        std::cout << f << std::endl;
        f.execute(b);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-----D-----" << std::endl;
    try
    {
        Bureaucrat b("the bur", 1);
        ShrubberyCreationForm f("nameOFFORM");
        f.beSigned(b);
        std::cout << f << std::endl;
        f.execute(b);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}