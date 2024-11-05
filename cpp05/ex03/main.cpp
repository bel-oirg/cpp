#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    std::cout << "-----A-----" << std::endl;
    AForm *af = NULL;
    try
    {
        Intern  pp;
        af = pp.makeForm("robotomy request", "a target2");
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete af;

    std::cout << "-----B-----" << std::endl;
    AForm *bf = NULL;
    try
    {
        Bureaucrat  b("the bur", 18);
        Intern      pp;
        bf = pp.makeForm("do not exist_FORM", "someone");
        bf->beSigned(b);

        bf->execute(b);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete bf;

    std::cout << "-----C-----" << std::endl;
    AForm *cf = NULL;
    try
    {
        Bureaucrat b("the bur", 5);
        Intern  pp;
        cf = pp.makeForm("presidential pardon", "a target2");
        cf->beSigned(b);
        b.signForm(*cf);
        // b.dec_grade()
        cf->execute(b);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete cf;
}