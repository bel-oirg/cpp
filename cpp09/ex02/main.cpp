#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
        return (std::cerr << "[-] Enter a valid expression" << std::endl, 1);
    PmergeMe b(argv + 1);
}