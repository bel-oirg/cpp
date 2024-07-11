/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:14:34 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/11 17:05:23 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
    protected:
    std::string type;
    
    public:
    Animal();
    ~Animal();
    Animal(std::string name);
    void makeSound(void) const;
    std::string getType(void) const;
};

class Dog:public Animal
{
    public:
    Dog();
    ~Dog();
};

class Cat:public Animal
{
    public:
    Cat();
    ~Cat();
};

class WrongAnimal
{
    protected:
    std::string type;
    
    public:
    WrongAnimal();
    ~WrongAnimal();
    WrongAnimal(std::string name);
    void makeSound(void) const;
    std::string getType(void) const;
};

class WrongCat:public WrongAnimal
{
    public:
    WrongCat();
};

#endif