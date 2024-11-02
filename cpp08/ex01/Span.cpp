#include "Span.hpp"

Span::Span(unsigned int N) : list_size(N)
{}

Span::Span() : list_size(0)
{}

Span::~Span()
{}

void Span::fastadd(unsigned int range)
{
    if (listed.size() + range > list_size)
        throw out_of_range();
    srand(time(NULL));
    for (unsigned int i = 0 ; i < range ; i++)
        addNumber(rand() % 10099000);
}

void Span::addNumber(int num)
{
    if (listed.size() == list_size)
        throw out_of_range();
    listed.push_back(num);
}

int Span::shortestSpan()
{
    if (listed.size() < 2)
        throw not_enough_nums();
    std::vector<int>::iterator sm = std::min_element(listed.begin(), listed.end());
    int sm_v = *sm;
    listed.erase(sm);
    int b_sm_v = *std::min_element(listed.begin(), listed.end());
    listed.push_back(*sm);
    return (b_sm_v - sm_v);
}

int Span::longestSpan()
{
    if (listed.size() < 2)
        throw not_enough_nums();
    return (*std::max_element(listed.begin(), listed.end()) - *std::min_element(listed.begin(), listed.end()));
}