/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 03:40:45 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/17 01:59:43 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
    std::cout << "A Dog is coming" << std::endl;
}

Dog &Dog::operator=(const Dog &cpy)
{
    if (this != &cpy)
    {
        delete brain;
        this->brain = new Brain(*cpy.brain);
        this->type = cpy.type;
    }
    return (*this);
}

Dog::Dog(const Dog &cpy) : brain(new Brain(*cpy.brain))
{
    this->type = cpy.type;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "A Dog is dead" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Dog: HawHaw!" << std::endl;
}