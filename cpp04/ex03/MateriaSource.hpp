/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:12:08 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/13 12:01:18 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
    AMateria *slots_bk[4];

    public:
    MateriaSource();
    ~MateriaSource();

    MateriaSource(const MateriaSource &cpy);
    MateriaSource &operator=(const MateriaSource &cpy);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};
