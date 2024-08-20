/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:19:26 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/20 09:20:19 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("")
{
    std::cout << "An Animal is initiated" << std::endl;
}

Animal::Animal(std::string name) : type(name)
{
    std::cout << name << " Animal is initiated" << std::endl;

}

Animal::Animal(const Animal &cpy)
{
    *this = cpy;
}

Animal &Animal::operator=(const Animal &cpy)
{
    if (this != &cpy)
        this->type = cpy.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "An Animal is dead" << std::endl;
}

void    Animal::makeSound(void) const
{
    std::cout << "Sound of animal" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}
