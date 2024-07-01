#include <iostream>

int main(int argc, char *argv[])
{
    int index;
    int c_index;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    index = 0;
    while(argv[++index])
    {
        c_index = -1;
        while (argv[index][++c_index])
            std::cout << (char)toupper(argv[index][c_index]);
    }
    std::cout << std::endl;
}