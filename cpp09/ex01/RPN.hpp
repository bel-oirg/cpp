#pragma once

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <stack>

class RPN
{
    private:
        std::stack<long long>  stk;
        std::string                 arg;

    public:
        void err_(int index);
        void get_val();
        RPN(std::string arg);

        //ORTHDX
        RPN();
        RPN(const RPN &cpy);
        RPN &operator=(const RPN &cpy);
        ~RPN();
};