/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:13:08 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/15 06:44:50 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string name) : type(name)
{
    std::cout << "A WrongAnimal is initiated" << std::endl;
}

WrongAnimal::WrongAnimal()
{
    std::cout << "A WrongAnimal is alive" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "A WrongAnimal is dead" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
    *this = cpy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &cpy)
{
    if (this != &cpy)
        this->type = cpy.type;
    return (*this);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal: ROARROAR!" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}
