#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (std::cerr << "Error: could not open file." << std::endl, 1);
    RPN b(argv[1]);
}