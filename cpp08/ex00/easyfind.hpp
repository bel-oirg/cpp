#pragma once

#include <list>
#include <algorithm>
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
int easyfind(T a, int val)
{
    typename T::iterator it = std::find(a.begin(), a.end(), val);
    if (it == a.end())
        throw (no_occurence_found());
    return(*it);
}