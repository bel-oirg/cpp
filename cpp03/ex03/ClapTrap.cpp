/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:40:28 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/13 02:33:29 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): Name("Default"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "The default constructor of ClapTrap is called"<< std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "Init of ClapTrap " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy) : Name(cpy.Name), HitPoints(cpy.HitPoints), EnergyPoints(cpy.EnergyPoints), AttackDamage(cpy.AttackDamage)
{
    std::cout << "Copy constructor of ClapTrap is called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &eq)
{
    if (this != &eq)
    {
        this->AttackDamage = eq.AttackDamage;
        this->EnergyPoints = eq.EnergyPoints;
        this->HitPoints = eq.HitPoints;
        this->Name = eq.Name;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destroying ClapTrap " << Name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (HitPoints && EnergyPoints)
    {
        EnergyPoints--;
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << "pts of damage!" << std::endl;
    }
    else
        std::cout << "Failed to attack" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (EnergyPoints && HitPoints)
    {
        this->HitPoints += amount, EnergyPoints--;
        std::cout << "ClapTrap " << Name << " is repairing by " << amount << " pts" << ", Hits " << HitPoints << std::endl;
    }
    else
        std::cout << "Failed to repair" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HitPoints <= amount)
    {
        std::cout << "ClapTrap is dead" << std::endl;
        this->HitPoints = 0;
    }
    else
    {
        std::cout << "ClapTrap is damaged with " << amount << " points"<< std::endl;
        this->HitPoints -= amount;
    }
}