#pragma once

#include <exception>
#include <vector>
#include <list>
#include <iostream>

class out_of_range : public std::exception
{
    public:
    virtual const char *what() const throw()
    {
        return ("[-] Out of range");
    }
};

class not_enough_nums : public std::exception
{
    public:
    virtual const char *what() const throw()
    {
        return ("[-] The numbers are not enough, no span can be found");
    }
};

class Span
{
    private:
        std::list<int> listed;
        unsigned int list_size;

    public:
    Span(unsigned int N);
    Span();
    ~Span();

    // void fastadd(int min, int max);
    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
};