/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:01:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/13 10:45:55 by bel-oirg         ###   ########.fr       */
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
    virtual ~AMateria(); //TODO MADE VIRTUAL
    std::string const & getType() const; //Returns the materia type
    
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

class Ice : public AMateria
{
    public:
    Ice();
    ~Ice();
    
    Ice(const Ice &cpy);
    Ice &operator=(const Ice &cpy);
    
    virtual void use(ICharacter& target);
    virtual Ice* clone() const; //check this line
};

class Cure : public AMateria
{
    public:
    Cure();
    ~Cure();  //TODO
    
    Cure(const Cure &cpy);
    Cure &operator=(const Cure &cpy);
    
    virtual void use(ICharacter& target);
    virtual Cure* clone() const;
};
