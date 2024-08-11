/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:59:31 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/11 17:49:01 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->HitPoints = 100;
    this->AttackDamage = 20;
    this->EnergyPoints = 50;
    std::cout << "Default constructor of ScavTrap is called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    this->HitPoints = 100;
    this->AttackDamage = 20;
    this->EnergyPoints = 50;
    std::cout << "ScavTrap " << Name << " is initalized" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& cpy) : ClapTrap(cpy.Name)
{
    this->HitPoints = cpy.HitPoints;
    this->AttackDamage = cpy.AttackDamage;
    this->EnergyPoints = cpy.EnergyPoints;
    std::cout << "Copy constructor of ScavTrap is called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &eq)
{
    if (this != &eq)
        ClapTrap::operator=(eq);
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap is destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate Keeper Mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (HitPoints && EnergyPoints)
        std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << AttackDamage << "pts of damage!" << std::endl;
    else
        std::cout << "Failed to attack" << std::endl;
}