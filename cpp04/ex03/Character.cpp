/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:57:05 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/13 11:33:11 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    int index = -1;
    while (++index < 4)
        this->slots[index] = nullptr;
    cout << "Character's constructor is called" << endl;
}

Character::Character(std::string Name) : Name(Name)
{
    int index = -1;
    while (++index < 4)
        this->slots[index] = nullptr;
    cout << "Character's " << Name << " constructor is called" << endl;
}


Character::~Character()
{
    cout << "Character's is destroyed" << endl;
}

Character &Character::operator=(const Character &cpy)
{
    int index = -1;

    if (this != &cpy)
    {
        this->Name = cpy.Name;
        while(cpy.slots[++index])
            this->slots[index] = cpy.slots[index];
    }
    return (*this); //TODO No need to copy type since it is intrinsic
}

Character::Character(const Character &cpy)
{
    *this = cpy;
}

const std::string &Character::getName() const
{
    return (this->Name);
}

void    Character::equip(AMateria *m)
{
    int index = -1;

    if (!m)
        return ; 
    while(++index < 4)
    {
        if (!this->slots[index])
        {
            this->slots[index] = m;
            cout << this->getName() << " Equipped " << m->getType() << endl;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (this->slots[idx])
    {
        delete this->slots[idx];
        this->slots[idx] = nullptr; //TODO remember the ptr
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (this->slots[idx])
        this->slots[idx]->use(target);
}