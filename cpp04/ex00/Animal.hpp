/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:14:34 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/15 06:27:22 by bel-oirg         ###   ########.fr       */
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
    /*
        Making base class destructor virtual guarantees
        that the object of derived class is destructed properly,
        both base class and derived class destructors are called.
    */
    Animal(std::string name);
    Animal(const Animal &cpy);
    Animal &operator=(const Animal &cpy);
    virtual ~Animal();
    /*
        Virtual functions should be accessed using a pointer
        or reference of base class type to achieve runtime polymorphism.
    */
    virtual void makeSound(void) const;
    std::string getType(void) const;
};

#endif