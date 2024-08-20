/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:59:45 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/14 04:53:52 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONTRAP_H
#define DIAMONTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamonTrap : public FragTrap, public ScavTrap
{
    private:
    std::string Name;
    unsigned int HitPoints;
    unsigned int EnergyPoints;
    unsigned int AttackDamage;

    public:
    DiamonTrap();
    DiamonTrap(std::string Name);
    DiamonTrap(const DiamonTrap &cpy);
    DiamonTrap &operator=(const DiamonTrap &eq);
    ~DiamonTrap();

    using ScavTrap::attack;
    void whoAmI();
};

#endif

/*  -Wshadow

    This flag enables warnings when a variable in a given scope 
    shadows another variable in an outer scope.
    "Shadowing" occurs when a variable declared in a narrower
    scope has the same name as one in a broader scope,
    making the outer variable inaccessible within that scope
*/

/*
    We inherited the claptrap as virtual class in
    the classes FragTrap and ScavTrap
    avoid two copies of ClapTrap in DiamonTrap class.

    It's the responsibility of the most derived class (DiamonTrap) 
    to initialize the virtual base class (ClapTrap)
*/