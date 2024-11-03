#include "Bureaucrat.hpp"

int main()
{
    std::cout << "-------A--------" << std::endl;
    try
    {
        Bureaucrat a("A", 2147449);
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------B--------" << std::endl;
    try
    {
        Bureaucrat a("\144", 1);
        std::cout << a << std::endl;
        a.dec_grade();
        std::cout << a.getGrade() << std::endl;
        a.inc_grade();
        a.inc_grade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------C--------" << std::endl;
    try
    {
        Bureaucrat a("l9j3", 2);
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------D--------" << std::endl;
    try
    {
        Bureaucrat a("D", -15);
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---------------" << std::endl;
}