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

/*
NOTES:
STL standard template lib
    1- CONTAINERS are boxes in which we store data that require processing
        like list, map, stack ..

    2- ALGORIHMS for data processing
    
    3- FUNCTORS or (function objects) are our custom algos

    4- ITERATOS are used to navigate through the data inside containers



    ---#####Generic class####---
    template <typename T>
    class Calc
    {
        public:
        add(T a, T b)
        {
            return (a + b);
        }

        sub(T a, T b)
        {
            return (a - b);
        }
    };

    int main()
    {
        Clac<int> A;
        A.add(1, 14);
    }

    ---####LIST###---
    list<int> list;

    list.pus_back(14);
    list.pus_back(-6514);
    list.pus_front(1);

    ---####ITERATORS###--
    for (list<int>::iterator it = list.begin(); it != list.end() ; it++)
        std::cout << *it << std::endl;

    NOTE: we can use const_iterator for const list
*/