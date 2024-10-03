#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("a name", 312);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}