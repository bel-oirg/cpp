#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

int main()
{
    try
    {
        Bureaucrat b("the bur", 2);
        RobotomyRequestForm f("nameOFFORM");
        f.beSigned(b);
        f.execute(b);
        // Form a("a name", 1, 12);
        // a.beSigned(b);
        // std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}