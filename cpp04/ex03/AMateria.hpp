/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:01:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/20 09:22:31 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class ICharacter;
using std::cout;
using std::endl;

class AMateria
{
    protected:
    std::string type;

    public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria &cpy);
    AMateria &operator=(const AMateria &eq);
    virtual ~AMateria();
    std::string const & getType() const; //Returns the materia type
    
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};
