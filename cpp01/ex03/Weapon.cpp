#include "Weapon.hpp"

void    Weapon::setType(std::string new_type)
{
    type = new_type;
}

std::string    Weapon::getType() const
{
    return (type);
}
