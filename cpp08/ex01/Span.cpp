#include "Span.hpp"

Span::Span(unsigned int N) : list_size(N)
{}

Span::Span() : list_size(0)
{}

Span::~Span()
{}

// void Span::fastadd(int min, int max)
// {
//     for (std::list<int>::iterator it = listed.begin(); it != listed.end(); it++)
//     {
//         addNumber()
// }

void Span::addNumber(int num)
{
    if (listed.size() == list_size)
        throw out_of_range();
    int i = 0;
    for (std::list<int>::iterator it = listed.begin(); it != listed.end(); it++)
    {
        if (*it > num || ++i >= 3)
        {
            listed.insert(it, num);
            return ;
        }
        if (listed.back() <= num)
        {
            listed.push_back(num);
            return;
        }
    }
    listed.push_back(num);
}

int Span::shortestSpan()
{
    if (listed.size() < 2)
        throw not_enough_nums();
    int last = listed.front();
    listed.pop_front();
    int b_last = listed.front();
    listed.push_front(b_last);
    return abs(last - b_last); //negative
}

int Span::longestSpan()
{
    if (listed.size() < 2)
        throw not_enough_nums();
    return abs(listed.front() - listed.back()); //negative
}