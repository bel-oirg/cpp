#include "Zombie.hpp"

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " is dead" << std::endl;
}

void    Zombie::set_name(std::string arg)
{
    name = arg;
}

