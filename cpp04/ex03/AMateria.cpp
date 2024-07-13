/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:19:31 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/13 11:21:28 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ---------AMATERIA */

AMateria::AMateria(std::string const & type) : type(type)
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
    *this = cpy; //TODO WHYCHANGE THIS
}

// AMateria &AMateria::operator=(const AMateria &eq)
// {
//     if (this != &eq)
//         *this = eq;
//     return (*this);
// }

void AMateria::use(ICharacter& target)
{
    cout << "Amateria " << this->getType() << " is used by " << target.getName() << endl;
}