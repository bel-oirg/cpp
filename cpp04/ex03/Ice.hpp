/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:53:30 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/18 00:31:30 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
    Ice();
    ~Ice();  //TODO
    
    Ice(const Ice &cpy);
    Ice &operator=(const Ice &cpy);
    
    virtual void use(ICharacter& target);
    virtual Ice* clone() const;
};
