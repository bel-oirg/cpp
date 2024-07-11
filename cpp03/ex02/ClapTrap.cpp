/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:40:28 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/11 11:54:06 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(10), EnergytPoints(10), AttackDamage(0)
{
    std::cout << "Init of ClapTrap " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy) : Name(cpy.Name), HitPoints(cpy.HitPoints), EnergytPoints(cpy.EnergytPoints), AttackDamage(cpy.AttackDamage) {}

ClapTrap &ClapTrap::operator=(const ClapTrap &eq)
{
    if (this != &eq)
    {
        this->AttackDamage = eq.AttackDamage;
        this->EnergytPoints = eq.EnergytPoints;
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
    if (HitPoints && EnergytPoints)
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << "pts of damage!" << std::endl;
    else
        std::cout << "Failed to attack" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amout)
{
    if (EnergytPoints && HitPoints)
    {
        this->HitPoints += amout, EnergytPoints--;
        std::cout << "ClapTrap " << Name << "is repairing by " << amout << " pts" << ", Hits " << HitPoints << std::endl;
    }
    else
        std::cout << "Failed to repair" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amout)
{
    if (this->HitPoints <= amout)
    {
        std::cout << "ClapTrap is dead" << std::endl;
        this->HitPoints = 0;
    }
    else
        this->HitPoints -= amout;
}