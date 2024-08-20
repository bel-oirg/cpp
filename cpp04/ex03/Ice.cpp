/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:52:46 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/20 10:01:29 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

void Ice::use(ICharacter& target)
{
    cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}

Ice::Ice() : AMateria("ice")
{
    // cout << "Ice Constructor is called" << endl;
}

Ice::~Ice()
{
    // cout << "Ice Destructor is called" << endl;
}

Ice* Ice::clone() const
{
    return (new Ice(*this));
}

Ice::Ice(const Ice &cpy) : AMateria("ice")
{
    *this = cpy;
}

Ice &Ice::operator=(const Ice &cpy)
{
    if (this != &cpy)
        this->type = cpy.type;
    return (*this);
}
