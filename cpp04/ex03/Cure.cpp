/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:48:57 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/18 05:51:52 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    // cout << "Cure Constructor is called" << endl;
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

Cure::~Cure()
{
    // cout << "Cure Destructor is called" << endl;
}

void Cure::use(ICharacter& target)
{
    cout << "* heals " << target.getName() << "'s wounds *" << endl;
}

Cure* Cure::clone() const
{
    return (new Cure(*this)); //TODO leaks ????/???>
}