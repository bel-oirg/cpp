/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 03:39:18 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/20 09:47:27 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
    this->type = "Cat";
    std::cout << "The Cat is constructed" << std::endl;
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
