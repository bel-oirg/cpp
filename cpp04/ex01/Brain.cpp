/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:47:25 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/20 09:35:20 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "The Brain is constructed" << std::endl;
}

Brain::Brain(const Brain &cpy)
{
    int i = -1;

    while (++i < MAX_IDEAS)
        this->ideas[i] = cpy.ideas[i];
    std::cout << "The Brain's cpy construstor is called" << std::endl;
}

Brain &Brain::operator=(const Brain &cpy)
{    
    if (this != &cpy)
    {
        int i = -1;

        while (++i < MAX_IDEAS)
            this->ideas[i] = cpy.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "The Brain is destructed" << std::endl;
}