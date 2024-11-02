#include "Span.hpp"

int main()
{
    Span s(20);

    s.addNumber(912);
    s.addNumber(172);
    s.addNumber(54312);
    s.addNumber(112);
    s.addNumber(932112);
    s.addNumber(17122);
    s.addNumber(541312);
    s.addNumber(1112);
    s.addNumber(9132);
    s.addNumber(17782);
    s.addNumber(5433312);
    s.addNumber(1192);
    s.addNumber(37912);
    s.addNumber(176792);
    s.addNumber(543712);
    s.addNumber(2);
    s.addNumber(9);
    s.addNumber(211);
    s.addNumber(-3);
    try
    {
        std::cout << "The shortest " << s.shortestSpan() << std::endl;
        std::cout << "The longest " << s.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}