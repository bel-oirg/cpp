#include "HumanB.hpp"

void    HumanB::attack(void)
{
    if (w)
        std::cout << name << " attacks with their " << w->getType() << std::endl;
    else
        std::cout << name << " attacks with their hands" << std::endl;
}

void    HumanB::setWeapon(Weapon &new_w)
{
    w = &new_w;
}