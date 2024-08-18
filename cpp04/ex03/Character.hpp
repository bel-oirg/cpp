/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:57:13 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/18 08:40:38 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"


typedef struct s_lnk_char
{
    AMateria    *ptr;
    s_lnk_char  *next;
}   t_lnk_char;

class Character : public ICharacter
{
    private:
    std::string Name;
    AMateria    *slots[4];
    t_lnk_char  *head;
    t_lnk_char  *tmp;

    public:
    Character();
    Character(std::string Name);
    Character(const Character &cpy);
    Character &operator=(const Character &cpy);
    ~Character();
    
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};
