/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:53:12 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/18 01:10:49 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class AMateria;

class ICharacter
{
    public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

/*
    ->Pure abstract classes cannot be instantiated directly
    
    -> Derived classes must override the pure virtual
    functions to be instantiable unless they are also abstract.

    -> Interface is This is a class where all the member functions
    are pure virtual functions
    -> Interface can be used as a pointer to Implementation
*/