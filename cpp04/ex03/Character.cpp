/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:57:05 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/20 10:05:35 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    this->uneq_index = -1;
    int index = -1;
    while (++index < 4)
        this->slots[index] = NULL, 
        this->uneq[index] = NULL;
    // cout << "Character's constructor is called" << endl;
}

Character::Character(std::string Name) : Name(Name)
{
    int index = -1;
    this->uneq_index = -1;
    while (++index < 4)
        this->slots[index] = NULL,
        this->uneq[index] = NULL;
    // cout << "Character's " << Name << " constructor is called" << endl;
}

Character &Character::operator=(const Character &cpy)
{
    int index = 0;

    if (this != &cpy)
    {
        this->Name = cpy.Name;
        while(index < 4)
        {
            delete this->slots[index];
            this->slots[index] = cpy.slots[index]->clone();
            index++;
        }
    }
    return (*this);
}

Character::Character(const Character &cpy)
{
    // cout << "copy assignment of character is called" << endl;
    this->uneq_index = -1;
    int index = -1;
    while (++index < 4)
        this->slots[index] = NULL, 
        this->uneq[index] = NULL;
    *this = cpy;
}

Character::~Character()
{
    int index = -1;
    
    while(++index < 4)
    {
        if (slots[index])
        {
            delete slots[index];
            slots[index] = NULL;
        }
        if (uneq[index])
        {
            delete uneq[index];
            uneq[index] = NULL;
        }
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
        if (uneq[index])
        {
            delete uneq[index];
            uneq[index] = NULL;
        }
    }
    uneq_index = -1; //re init the uneq array (bkup)
    index = -1;
    while(++index < 4)
    {
        if (!this->slots[index])
        {
            this->slots[index] = m;
            // cout << this->getName() << " Equipped " << m->getType() << endl;
            return ;
        }
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->slots[idx])
    {
        this->uneq[++uneq_index] = this->slots[idx]; //remember the ptr before unequip
        this->slots[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->slots[idx])
        this->slots[idx]->use(target);
}