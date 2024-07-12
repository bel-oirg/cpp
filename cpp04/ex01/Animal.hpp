/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:14:34 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/12 11:22:08 by bel-oirg         ###   ########.fr       */
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
    declaring the desctructor as virtual to ensure that the virtual
    keyword that ensures both base class and the derived class
    destructor will be called at run time, it called the derived
    class first and then base class to release the space occupied
    by both destructors
    Virtual destructors are useful when you might potentially delete an instance 
    of a derived class through a pointer to base class:
    */
    Animal(std::string name);
    Animal(const Animal &cpy);
    Animal &operator=(const Animal &cpy);
    virtual void makeSound(void) const;
    std::string getType(void) const;
};

class Dog:public Animal
{
    private:
    Brain *brain;
    
    public:
    Dog();
    ~Dog();
    /*
    Shallow copy copies all the member field values
    Deep copy, makes the copies of dynamically allocated memory
    */
    Dog(const Dog& cpy);
    Dog &operator=(const Dog& cpy);
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