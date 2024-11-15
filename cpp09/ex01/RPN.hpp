#pragma once

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <stack>

class RPN
{
    private:
        std::string       arg;
        std::stack<char>  rpn;
        std::stack<char>  stk;

    public:
        RPN(std::string arg);
        ~RPN();
};