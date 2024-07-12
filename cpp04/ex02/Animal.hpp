/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:14:34 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/12 11:23:27 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include "Brain.hpp"
#include <iostream>

class Animal
{
    protected:
    std::string type;
    
    public:
    Animal();
    virtual ~Animal();
    /*
    Abstract class contains as least one pure virtual ft
    */
    Animal(std::string name);
    Animal(const Animal &cpy);
    Animal &operator=(const Animal &cpy);
    /*
    You can not create an instance of an abstract base class, but you can
    create other classes that are derived from it

    I CAN NOT DO THIS : Animal cat;
    */
    virtual void makeSound(void) const = 0;
    /*
    A pure virtual function is a virtual member ft that belongs to a base
    class and needs to be redefined in derived classes
    */
    std::string getType(void) const;
};

class Dog:public Animal
{
    private:
    Brain *brain;
    
    public:
    Dog();
    ~Dog();
    Dog(const Dog& cpy);
    Dog &operator=(const Dog& cpy);
    /*
    If I did not overrided this exact ft, also this class will become abstract
    */
    virtual void makeSound(void) const;
};

class Cat:public Animal
{
    private:
    Brain *brain;

    public:
    Cat();
    ~Cat();
    Cat(const Cat& cpy);
    Cat &operator=(const Cat& cpy);
    virtual void makeSound(void) const;
};

#endif