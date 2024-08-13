/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:59:33 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/13 23:37:24 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
    ScavTrap();
    ScavTrap(std::string Name);
    ScavTrap(const ScavTrap& cpy);
    ScavTrap &operator=(const ScavTrap &eq);
    ~ScavTrap();

    void guardGate();
    void attack(const std::string& target);
    //method overriding
};

#endif

/*
    The inheritance allows a class to inherit properties and behaviors 
    (i.e., member variables and member functions) from another class.
    The class that inherits is called the derived class (or child class),
    and the class being inherited from is called the base class
*/

/*
    In cpp we have 3 types of inheritance (pub, protected, prv)

    class DerivedPublic : public Base
    {
        public_data is public
        protected_data is protected
        private_data is inaccessible
    };

    class DerivedProtected : protected Base
    {
        public_data is protected
        protected_data is protected
        private_data is inaccessible
    };

    class DerivedPrivate : private Base
    {
        public_data is private
        protected_data is private
        private_data is inaccessible
    };
*/

/*
    Without a virtual destructor in Base,
    deleting basePtr would only call Base's destructor,
    potentially leading to resource leaks.

    A virtual destructor ensures that when
    you delete an object through a pointer to the base class,
    the derived class's destructor is called first,
    followed by the base class's destructor.
    This is crucial when your derived class manages
    resources (e.g., dynamic memory, file handles)
    that need to be released.
*/