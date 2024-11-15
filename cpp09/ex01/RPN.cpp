#include "RPN.hpp"

RPN::RPN(std::string arg)
{
    size_t         opr_index;
    std::string opr = "+-*/";

    for (size_t index = 0; index < arg.size(); index++)
    {
        if (arg[index] == ' ')
            index++;

        if (isdigit(arg[index]))
            rpn.push(arg[index]);
        else
        {
            opr_index = opr.find(arg[index]);
            if (opr_index == std::string::npos)
            {
                std::cerr << "Invalid input." << std::endl;
                exit(1);
            }
            else if (stk.empty())
            {
                stk.push(arg[index]);
            }
            else if (opr_index < 2) //in FOUND    + || -
            {
                while(!stk.empty())
                {
                    rpn.push(stk.top());
                    stk.pop();
                }
                stk.push(arg[index]);
            }
            else if (opr_index < 4) //in FOUND   * || /
            {
                if (opr.find(stk.top()) < 2)
                    stk.push(arg[index]);
                else if (opr.find(stk.top()) < 4) 
                {
                    while(!stk.empty())
                    {
                        rpn.push(stk.top());
                        stk.pop();
                    }
                    stk.push(arg[index]);
                }
            }
        }
    }
    while(!stk.empty())
    {
        rpn.push(stk.top());
        stk.pop();
    }
}

RPN::~RPN()
{
    std::cout << "this is rpn" << std::endl;
    while(!rpn.empty())
    {
        std::cout << rpn.top() << std::endl;
        rpn.pop();
    }

    std::cout << "this is stk" << std::endl;
    while(!stk.empty())
    {
        std::cout << stk.top() << std::endl;
        stk.pop();
    }
}
