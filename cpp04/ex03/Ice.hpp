/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:53:30 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/20 05:18:40 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
    Ice();
    ~Ice();
    
    Ice(const Ice &cpy);
    Ice &operator=(const Ice &cpy);
    
    void use(ICharacter& target);
    Ice* clone() const;
};
