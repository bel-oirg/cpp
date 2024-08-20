/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 03:40:45 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/20 09:45:36 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "A Dog is constucted" << std::endl;
}

Dog &Dog::operator=(const Dog &cpy)
{
    if (this != &cpy)
        this->type = cpy.type;
    return (*this);
}

Dog::Dog(const Dog &cpy)
{
    *this = cpy;
}

Dog::~Dog()
{
    std::cout << "A Dog is dead" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Dog: HawHaw!" << std::endl;
}