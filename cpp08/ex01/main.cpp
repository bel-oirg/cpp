#include "Span.hpp"

int main()
{
    {
        Span s(17);
        std::vector<int> p_s;

        p_s.push_back(165);
        p_s.push_back(123);
        p_s.push_back(33);
        p_s.push_back(983);
        p_s.push_back(132);
        p_s.push_back(3);
        try
        {
            s.fastadd(p_s.begin(), p_s.end());
            std::cout << "The shortest " << s.shortestSpan() << std::endl;
            std::cout << "The longest " << s.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
}
