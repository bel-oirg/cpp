#include "real_type.hpp"

Base *generate(void)
{
    Base *p;

    srand(time(NULL));
    int a_num = rand() % 3;
    printf("%d\n", a_num);
    if (!a_num)
        p = new A;
    else if (a_num == 1)
        p = new B;
    else
        p = new C;
    return (p);
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "A type" << std::endl;
        return;
    }
    if (dynamic_cast<B *>(p))
    {
        std::cout << "B type" << std::endl;
        return;
    }
    if (dynamic_cast<C *>(p))
    {
        std::cout << "C type" << std::endl;
        return;
    }
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A type" << std::endl;
        return;
    }
    catch (std::exception &e)
    {
        (void)e;
    }

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B type" << std::endl;
        return;
    }
    catch (std::exception &e)
    {
        (void)e;
    }

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C type" << std::endl;
        return;
    }
    catch (std::exception &e)
    {
        (void)e;
    }
}
