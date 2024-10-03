#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("a name", 2147483649);
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}