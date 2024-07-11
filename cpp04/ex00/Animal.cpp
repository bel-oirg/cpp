/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:19:26 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/11 17:18:25 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(std::string name) : type(name)
{
    std::cout << "An Animal is initiated" << std::endl;

}

Animal::Animal()
{
    std::cout << "An Animal is initiated" << std::endl;

}
Animal::~Animal()
{
    std::cout << "An Animal is dead" << std::endl;

}

void Animal::makeSound(void) const
{
    if (type == "Cat")
        std::cout << "The Cat is meowing" << std::endl;
    else if (type == "Dog")
        std::cout << "The Dog is barking" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

Dog::Dog() : Animal("Dog")
{
    std::cout << "A Dog is coming" << std::endl;
}

Dog::~Dog()
{
    std::cout << "A Dog is dead" << std::endl;
}

Cat::Cat() : Animal("Cat")
{
    std::cout << "The Cat woke up :)" << std::endl;
}

Cat::~Cat()
{
    std::cout << "The Cat is dead :)" << std::endl;
}

/*  WRNG  */

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

void WrongAnimal::makeSound(void) const
{
    if (!getType().empty())
        std::cout << "The Cat is roaring" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "The WrongCat woke up :)" << std::endl;
}