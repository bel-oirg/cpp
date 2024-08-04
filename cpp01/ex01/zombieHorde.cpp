#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* zombies;
    int     index;

    /*
    N > 0 
    */
    zombies = new Zombie[N];
    index = -1;
    while(++index < N)
        zombies[index].set_name(name);
    return (zombies);
}