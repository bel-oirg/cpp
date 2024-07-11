/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:59:31 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/11 16:08:16 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    this->HitPoints = 100;
    this->AttackDamage = 20;
    this->EnergytPoints = 50;
    std::cout << "ScavTrap " << Name << " is initalized" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << " is destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate Keeper Mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (HitPoints && EnergytPoints)
        std::cout << "ScavTrap :) " << Name << " attacks " << target << ", causing " << AttackDamage << "pts of damage!" << std::endl;
    else
        std::cout << "Failed to attack" << std::endl;
}

//TODO CHANGE Scav TO SCAV