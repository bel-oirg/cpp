/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 03:39:18 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/15 06:53:03 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "The Cat woke up :)" << std::endl;
}

Cat &Cat::operator=(const Cat &cpy)
{
    if (this != &cpy)
        this->type = cpy.type;
    return (*this);
}

Cat::Cat(const Cat &cpy)
{
    *this = cpy;
}

Cat::~Cat()
{
    std::cout << "The Cat is dead :)" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Cat: Meow!" << std::endl;
}
