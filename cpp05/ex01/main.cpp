#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "-----A-----" << std::endl;
    try
    {
        Bureaucrat b("the bur", 2);
        Form a("a name", 3, 12);
        a.beSigned(b);

        b.dec_grade();
        b.dec_grade();
        b.dec_grade();
        b.dec_grade(); //grade bur 6
        b.signForm(a);
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-----B-----" << std::endl;
    try
    {
        Bureaucrat b("the bur", 2);
        Form a("a name", 3, 12);
        a.beSigned(b);

        b.inc_grade();
        b.inc_grade();
        b.inc_grade();
        b.signForm(a);
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-----C-----" << std::endl;
    try
    {
        Bureaucrat b("THE BU2", 12);
        Form a("CONTRACT", 17, 80);
        b.signForm(a);

        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}