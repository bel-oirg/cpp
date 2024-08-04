#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
    Zombie* inst;
    int N = 4;
    int index;

    index = -1;
    inst = zombieHorde(1, "hell");
    while (++index < N)
        inst[index].announce();
    delete[] inst;
}