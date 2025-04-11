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
    double       a, b, res = LLONG_MAX;

    if (arg.empty())
        return (err_(0));

    std::stringstream arg_ss(arg);
    std::string chunk;
    while (arg_ss >> chunk)
    {
        if (chunk.empty())
            return (err_(0));
        if (chunk.size() > 2)
            return (err_(1));

        if ((chunk.size() == 2) && (chunk[0] == '-') && (std::isdigit(chunk[1])))
            stk.push(static_cast<int>(-(chunk[1] - 48)));
        else if ((chunk.size() == 1) && (std::isdigit(chunk[0])))
            stk.push(static_cast<int>(chunk[0] - 48));
        else
        {
            if (chunk.size() > 1)
                return (err_(1));

            opr_index = opr.find(chunk);
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