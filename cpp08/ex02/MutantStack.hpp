#pragma once

#include <stack>
#include <iostream>

/*
    The default underlaying container of stack is deque
*/

template<typename T>
class MutantStack : public std::stack<T> // std::stack<T, std::deque<T> >
{
    public:
        typedef typename std::deque<T>::iterator        iterator;
        typedef typename std::deque<T>::const_iterator  const_iterator;

        //ORTHDX
        MutantStack() {}
        ~MutantStack() {}
        MutantStack(const MutantStack &stack)
        {
            *this = stack;
        }
        MutantStack &operator=(const MutantStack &stack)
        {
            std::stack<T>::operator=(stack); //using the assign op of the base c;ass
            return (*this);
        }

        const_iterator begin() const { return (this->c.begin()); }
        const_iterator end() const { return (this->c.end()); }

        iterator begin() { return (this->c.begin()); }
        iterator end() { return (this->c.end()); } 
};