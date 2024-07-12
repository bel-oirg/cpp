/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:19:26 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/12 09:36:07 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
/*
vitual ft inside a class is used to execute the ft of the most derived class

virtual void MakeSound() = 0  //that is a pure virtual ft
abstract class is class that has at least one pure virtual ft
every class that inherit from our class, will have to provide its own implementation for that ft
*/

Animal::Animal(std::string name) : type(name)
{
    std::cout << name << " Animal is initiated" << std::endl;
}

Animal::Animal()
{
    std::cout << "An Animal is initiated" << std::endl;
}
Animal::~Animal()
{
    std::cout << "An Animal is dead" << std::endl;
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

// void    Animal::makeSound(void) const
// {
//     std::cout << "Sound of animal" << std::endl;
// }

std::string Animal::getType(void) const
{
    return (this->type);
}

Dog::Dog() : Animal("Dog")
{
    std::cout << "A Dog is coming" << std::endl;
    this->brain = new Brain();
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "A Dog is dead" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "HawHaw!" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

Cat::Cat() : Animal("Cat")
{
    this->brain = new Brain();
    std::cout << "The Cat woke up :)" << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "The Cat is dead :)" << std::endl;
}
