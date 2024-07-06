#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
    private:
    std::string name;
    Weapon      *w;

    public:
    HumanB(std::string name) : name(name), w(nullptr) {}
    void    setWeapon(Weapon &new_w);
    void    attack(void);
};

#endif