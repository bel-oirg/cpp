#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    try
    {
        Bureaucrat b("the bur", 188);
        ShrubberyCreationForm ff("TREE");
        // PresidentialPardonForm pardon("pardon_name");
        // pardon.beSigned(b);
        // pardon.execute(b);
        ff.beSigned(b);
        b.executeForm(ff);
        ff.execute(b);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
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
}