/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:19:31 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/13 10:14:00 by bel-oirg         ###   ########.fr       */
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
    cout << "Amateria " << this->getType() << " is used by " << target.getName() << endl;
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
