#include "RPN.hpp"

void    RPN::err_(int index)
{
    if (index == 0)
        std::cerr << "[-] Empty input" << std::endl;
    else if (index == 1)
        std::cerr << "[-] Invalid input." << std::endl;
    else if (index == 2)
        std::cerr << "[-] Invalid Mathematical Exp." << std::endl;
    else if (index == 3)
        std::cerr << "[-] Over/Underflow possibility." << std::endl;
}

void    RPN::get_val()
{
    size_t          opr_index;
    std::string     opr = "+-*/";
    long long       a, b, res = LLONG_MAX;

    if (arg.empty())
        return (err_(0));
    for (size_t index = 0; index < arg.size(); index++)
    {
        if (index % 2)
        {
            if (arg[index] == ' ')
                index++;
            else
                return (err_(1));
        }
        if (isdigit(arg[index]))
            stk.push(static_cast<int>(arg[index]) - 48);
        else
        {
            opr_index = opr.find(arg[index]);
            if (opr_index == std::string::npos || stk.size() < 2)
                return (err_(1));
            b = stk.top();
            stk.pop();
            a = stk.top();
            stk.pop();
            if (opr_index == 0)
                res = a + b;
            else if (opr_index == 1)
                res = a - b;
            else if (opr_index == 2)
                res = a * b;
            else if (opr_index == 3)
            {
                if (!b)
                    return (err_(2));
                res = a / b;
            }
            if (res > INT_MAX || res < INT_MIN)
                return (err_(3));
            stk.push(res);
        }
    }
    if (stk.size() != 1 || res == LLONG_MAX)
        return (err_(1));
    std::cout << res << std::endl;
}

RPN::RPN(std::string arg) : arg(arg) {}

RPN::RPN() {}

RPN::RPN(const RPN &cpy)
{
    *this = cpy;
}

RPN &RPN::operator=(const RPN &cpy)
{
    this->stk = cpy.stk;
    this->arg = cpy.arg;
    return (*this);
}

RPN::~RPN() {}