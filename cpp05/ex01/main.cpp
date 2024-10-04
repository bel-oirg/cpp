#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form a("a name", 12, 12);
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}