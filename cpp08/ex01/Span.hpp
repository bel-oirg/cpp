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
        std::vector<int> listed;
        unsigned int list_size;

    public:
    Span(unsigned int N);
    Span();
    ~Span();

    void fastadd(unsigned int range);
    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
};