#pragma once

#include "Base.hpp"
#include "iostream"

class Base
{
    public:
        virtual ~Base();
};

Base *generate(void);
void identify(Base* p);