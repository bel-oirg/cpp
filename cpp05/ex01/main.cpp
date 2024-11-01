#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b("the bur", 2);
        Form a("a name", 3, 12);
        b.signForm(a);
        // a.beSigned(b);
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}