/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:19:31 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/13 08:06:57 by bel-oirg         ###   ########.fr       */
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

Cure::Cure() : AMateria("cure")
{
    cout << "Cure Constructor is called" << endl;
}

Cure::~Cure()
{
    cout << "Cure Destructor is called" << endl;
}

Cure* Cure::clone() const
{
    return (new Cure(*this)); //TODO leaks ????/???>
}

Cure::Cure(const Cure &cpy) : AMateria(cpy.type)
{
    *this = cpy;
}

Cure &Cure::operator=(const Cure &cpy)
{
    if (this != &cpy)
        this->type = cpy.type;
    return (*this); //TODO No need to copy type since it is intrinsic
}

/* ----------ICE */

void Ice::use(ICharacter& target)
{
    cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}

Ice::Ice() : AMateria("ice")
{
    cout << "Ice Constructor is called" << endl;
}

Ice::Ice(const Ice &cpy) : AMateria(cpy.type) {} //TODO

Ice &Ice::operator=(const Ice &cpy)
{
    if (this != &cpy)
        this->type = cpy.type;
    return (*this); //TODO No need to copy type since it is intrinsic
}

Ice::~Ice()
{
    cout << "Ice Destructor is called" << endl;
}

Ice* Ice::clone() const
{
    return (new Ice(*this)); //TODO leaks
}

/* ----------CHARACTER */

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

MateriaSource::~MateriaSource()
{
    // int index = -1;
    // while(slots_bk[++index]) //TODO WHY I CANT
    //     delete slots_bk[index];
    cout << "MateriaSource is destructed" << endl;
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

MateriaSource::MateriaSource(const MateriaSource &cpy)
{
    *this = cpy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &cpy)
{
    int index = -1;

    while(cpy.slots_bk[++index])
        this->slots_bk[index] = cpy.slots_bk[index];
    return (*this);
}
