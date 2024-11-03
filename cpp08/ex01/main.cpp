#include "Span.hpp"

int main()
{
    Span s(1120000);

    try
    {
        s.fastadd(200000);
        std::cout << "The shortest " << s.shortestSpan() << std::endl;
        std::cout << "The longest " << s.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}