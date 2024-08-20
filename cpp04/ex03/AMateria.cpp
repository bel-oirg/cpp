/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:19:31 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/20 05:34:13 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    // cout << "AMateria is constructed" << endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
    // cout << "AMateria " << type << " is constructed" << endl;
}

AMateria::AMateria(const AMateria &cpy)
{
    (void)cpy;
}

AMateria &AMateria::operator=(const AMateria &eq)
{
    (void)eq;
    return (*this);
}

AMateria::~AMateria()
{
    // cout << "AMateria is destructed" << endl;
}

void AMateria::use(ICharacter& target)
{
    cout << "Amateria " << this->getType() << " is used by " << target.getName() << endl;
}

const std::string &AMateria::getType() const
{
    return (this->type);
}