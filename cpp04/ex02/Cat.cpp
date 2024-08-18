/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 03:39:18 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/16 07:27:27 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
    //TODO PROTECT THE NEW
    std::cout << "The Cat woke up :)" << std::endl;
}

Cat &Cat::operator=(const Cat &cpy)
{
    if (this != &cpy)
    {
        delete brain;
        this->brain = new Brain(*cpy.brain);
        this->type = cpy.type;
    }
    return (*this);
}
/*
    Deep Copy: Both the Brain and Cat classes implement deep copies.
    Each Brain object has its own array of std::string objects,
    and each Cat object has its own Brain object,
    ensuring that changes to one object do not affect the copied object.
*/
Cat::Cat(const Cat &cpy) : brain(new Brain(*cpy.brain))
{
    this->type = cpy.type;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "The Cat is dead :)" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Cat: Meow!" << std::endl;
}
