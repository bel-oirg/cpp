/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:22:36 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/11 16:05:42 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamonTrap.hpp"

DiamonTrap::DiamonTrap(std::string Name) : ClapTrap(Name + "_clap_name"), FragTrap(Name),ScavTrap(Name)
{
    this->Name = Name;
    this->HitPoints = FragTrap::HitPoints;
    this->EnergytPoints = ScavTrap::EnergytPoints;
    this->AttackDamage = FragTrap::AttackDamage;
    std::cout << "Diamon Trap " << Name << " is initiated" << std::endl;
}
void DiamonTrap::whoAmI()
{
    std::cout << this->Name << " - " << ClapTrap::Name << std::endl; 
}

DiamonTrap::~DiamonTrap()
{
    std::cout << "DiamonTrap is destroyed" << std::endl;
}