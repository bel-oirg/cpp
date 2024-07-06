#include "Zombie.hpp"

int main()
{
    Zombie      *attr_heaped;
    std::string name;

    std::cout << "Enter the name of stacked zombie :";
    std::cin >> name;
    Zombie attr(name);
    attr.annouce();

    std::cout << "Enter the name of heaped zombie :";
    std::cin >> name;
    attr_heaped = attr_heaped->newZombie(name);
    attr_heaped->annouce();
    delete attr_heaped;
}