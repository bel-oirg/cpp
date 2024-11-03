#pragma once

#include <stack>
#include <deque>
#include <iostream>

/*
    here i am inheriting from stack class and 
*/

template<typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
    public:
        typedef typename std::deque<T>::iterator iterator;

        MutantStack() {}
        ~MutantStack() {}
        MutantStack(const MutantStack &stack)
        {
            *this = stack;
        }
        iterator begin() 
        {
            return (this->c.begin());
        }
        iterator end()
        {
            return (this->c.end());  //TODO if i removed this i won't work WHY
        }
        //maybe add const_iterator and some consts
};