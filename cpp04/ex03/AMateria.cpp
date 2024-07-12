/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:19:31 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/12 15:22:05 by bel-oirg         ###   ########.fr       */
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
    // this->type = cpy.type;
}

AMateria &AMateria::operator=(const AMateria &eq)
{
    if (this != &eq)
        *this = eq;
    return (*this);
}

void AMateria::use(ICharacter& target) {}

/* ---------CURE */
void Cure::use(ICharacter& target)
{
    cout << "* heals " << target.getName() << "'s wounds *" << endl;
}

void Ice::use(ICharacter& target)
{
    cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
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
    cout << "* heals " << target.getName() << "'s wounds *" << endl;
}

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
    cout << "Character's constructor is called" << endl;
    this->slots = new AMateria[4];
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
    if (this->slots)
}