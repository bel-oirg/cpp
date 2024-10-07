#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

void f()
{
    system("leaks Intern");
}

int main()
{
    AForm *af;
    atexit(f);
    try
    {
        Bureaucrat b("the bur", 18);
        Intern  pp;
        af = pp.makeForm("robotomy request", "a target2");
        af->beSigned(b);
        af->execute(b);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete af;
}