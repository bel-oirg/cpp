#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (std::cerr << "[-] Enter an inverted Polish mathematical expression" << std::endl, 1);
    RPN b(argv[1]);
    b.get_val();
}