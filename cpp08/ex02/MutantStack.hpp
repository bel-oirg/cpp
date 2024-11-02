#pragma once

#include <stack>
#include <iostream>

template<typename T>
class MutantStack
{
    private:
        std::stack<T> stk;

    public:
        MutantStack(){}
        ~MutantStack(){}
        MutantStack(const MutantStack &stack)
        {
            *this = stack;
        }

        f
        size_type size() const
        {
            return (stk.size());
        }
        bool empty() const
        {
            return (stk.empty());
        }
        void push(const T& val)
        {
            stk.push(T);
        }
        void pop()
        {
            stk.pop();
        }
        const T& top() const
        {
            return (stk.top());
        }
};