#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b("the bur", 2);
        Form a("a name", 1, 12);
        a.beSigned(b);
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}