/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:57:05 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/18 10:10:09 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    head = new t_lnk_char;
    head->next = NULL;
    tmp = head;

    int index = -1;
    while (++index < 4)
        this->slots[index] = NULL;
    // cout << "Character's constructor is called" << endl;
}

Character::Character(std::string Name) : Name(Name)
{
    int index = -1;
    while (++index < 4)
        this->slots[index] = NULL;
    // cout << "Character's " << Name << " constructor is called" << endl;
}

Character &Character::operator=(const Character &cpy)
{
    int index = -1;
    cout << "copy assignment " << endl;
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

Character::~Character()
{
    int index = 0;
    while(index < 4 && slots[index])
    {
        delete slots[index];
        slots[index++] = NULL;
    }
    // cout << "Character's is destroyed" << endl;
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
            tmp->ptr = m;
            tmp = tmp->next;

            this->slots[index] = m;
            cout << this->getName() << " Equipped " << m->getType() << endl;
            return ;
        }
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->slots[idx])
    {
        // delete this->slots[idx];
        this->slots[idx] = NULL; //TODO remember the ptr
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->slots[idx])
        this->slots[idx]->use(target);
}