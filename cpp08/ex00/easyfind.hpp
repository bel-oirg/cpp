#pragma once

#include <list>
#include <exception>
#include <iostream>

class no_occurence_found : public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return ("[-] No occurence found");
    }
};

template <typename T>
int easyfind(const T &a, int val)
{
    typename T::const_iterator it;

    for (it = a.begin(); it != a.end() ; it++)
        if (*it == val)
            return (*it);
    throw (no_occurence_found());
}