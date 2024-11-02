#include "Span.hpp"

int main()
{
    Span s(220);

    s.fastadd(133);
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