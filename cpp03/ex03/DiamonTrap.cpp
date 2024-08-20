/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:22:36 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/14 04:47:04 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamonTrap.hpp"

DiamonTrap::DiamonTrap() : ClapTrap("Default_clap_name")
{
    this->Name = "Default";
    this->HitPoints = 100; //100
    this->EnergyPoints = 50; //50
    this->AttackDamage = 30; //30
    std::cout << "Default DiamonTrap constructor is called" << std::endl;
}

DiamonTrap::DiamonTrap(std::string Name) : ClapTrap(Name + "_clap_name"),  FragTrap(Name), ScavTrap(Name)
{
    this->Name = Name;
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 30;
    std::cout << "DiamonTrap " << Name << " is initiated" << std::endl;
}

DiamonTrap::DiamonTrap(const DiamonTrap& cpy) : ClapTrap(cpy.Name + "_clap_name")
{
    std::cout << "Copy constructor of DiamonTrap is called" << std::endl;
    this->Name = cpy.Name;
    this->HitPoints = cpy.HitPoints;
    this->AttackDamage = cpy.AttackDamage;
    this->EnergyPoints = cpy.EnergyPoints;
}

DiamonTrap &DiamonTrap::operator=(const DiamonTrap &eq)
{
    if (this != &eq)
    {
        this->Name = eq.Name;
        this->HitPoints = eq.HitPoints;
        this->AttackDamage = eq.AttackDamage;
        this->EnergyPoints = eq.EnergyPoints;
    }
    return (*this);
}

DiamonTrap::~DiamonTrap()
{
    std::cout << "DiamonTrap is destroyed" << std::endl;
}

void DiamonTrap::whoAmI()
{
    std::cout << this->Name << " - " << ClapTrap::Name << std::endl; 
}
