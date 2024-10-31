#include "real_type.hpp"

int main()
{
    Base    *p;

    p = generate();
    identify(p);
    identify(*p);
    delete p;
}