/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:12:35 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/13 12:13:41 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    int index = -1;
    
    while (++index < 4)
        this->slots_bk[index] = nullptr;
    cout << "MateriaSource constructor is called" << endl;
}

MateriaSource::~MateriaSource()
{
    // int index = -1;
    // while(slots_bk[++index]) //TODO WHY I CANT
    //     delete slots_bk[index];
    cout << "MateriaSource is destructed" << endl;
}

void MateriaSource::learnMateria(AMateria* new_m)
{
    int index = -1;

    while(++index < 4)
    {
        if (!this->slots_bk[index])
        {
            this->slots_bk[index] = new_m;
            cout << "Materia Learned " << new_m->getType() << endl;
            return ; 
        }
    }
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    int index = -1;

    while (++index < 4)
    {
        if (this->slots_bk[index] && type == this->slots_bk[index]->getType())
        {
            cout << "Materia " << type << " Created" << endl;
            return (this->slots_bk[index]->clone());
        }
    }
    return (0);
}

MateriaSource::MateriaSource(const MateriaSource &cpy)
{
    *this = cpy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &cpy)
{
    int index = -1;

    while(cpy.slots_bk[++index])
        this->slots_bk[index] = cpy.slots_bk[index];
    return (*this);
}
