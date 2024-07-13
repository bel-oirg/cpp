/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:19:31 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/13 05:06:46 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ---------AMATERIA */
AMateria::AMateria(std::string const & type)
{
    cout << "AMateria " << type << " is constructed" << endl;
}

AMateria::AMateria()
{
    cout << "AMateria is constructed" << endl;
}

AMateria::~AMateria()
{
    cout << "AMateria is destructed" << endl;
}

const std::string &AMateria::getType() const
{
    return (this->type);
}

AMateria::AMateria(const AMateria &cpy)
{
    this->type = cpy.type; //TODO CHANGE THIS
}

AMateria &AMateria::operator=(const AMateria &eq)
{
    if (this != &eq)
        *this = eq;
    return (*this);
}

void AMateria::use(ICharacter& target)
{
    (void) target;
}

/* ---------CURE */
void Cure::use(ICharacter& target)
{
    cout << "* heals " << target.getName() << "'s wounds *" << endl;
}

Cure::Cure()
{
    cout << "Cure Constructor is called" << endl;
}

Cure::~Cure()
{
    cout << "Cure Destructor is called" << endl;
}

Cure* Cure::clone() const
{
    return (new Cure()); //TODO leaks
}

/* ----------ICE */

void Ice::use(ICharacter& target)
{
    cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}

Ice::Ice()
{
    cout << "Ice Constructor is called" << endl;
}

Ice::~Ice()
{
    cout << "Ice Destructor is called" << endl;
}

Ice* Ice::clone() const
{
    return (new Ice()); //TODO leaks
}

/* ----------CHARACTER */

Character::Character()
{
    int index = -1;
    while (++index < 4)
        this->slots[index] = nullptr;
    cout << "Character's constructor is called" << endl;
}

Character::Character(std::string Name)
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
            return ; 
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return ;
    if (this->slots[idx])
        this->slots[idx] = nullptr; //TODO remember the ptr
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3 || !this->slots[idx])
        return ;
    this->slots[idx]->use(target);
}

/* MATERIASOURCE */

MateriaSource::MateriaSource()
{
    int index = -1;
    
    while (++index < 4)
        this->slots_bk[index] = nullptr;
    cout << "MateriaSource constructor is called" << endl;
}

void MateriaSource::learnMateria(AMateria* new_m)
{
    int index = -1;

    if (!new_m)
        return ; 
    while(++index < 4)
    {
        if (!this->slots_bk[index])
        {
            this->slots_bk[index] = new_m;
            return ; 
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int index = -1;

    while (++index < 4)
    {
        if (this->slots_bk[index] && type == this->slots_bk[index]->getType())
            return (this->slots_bk[index]);
    }
    return (0);
}