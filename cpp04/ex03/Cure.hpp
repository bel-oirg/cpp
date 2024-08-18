/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:49:12 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/17 04:13:48 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
    Cure();
    Cure(const Cure &cpy);
    Cure &operator=(const Cure &cpy);
    ~Cure();  //TODO
    
    virtual void use(ICharacter& target);
    virtual Cure* clone() const;
};
