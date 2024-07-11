/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScarvTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:59:31 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/11 11:55:49 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScarvTrap.hpp"

ScarvTrap::ScarvTrap(std::string Name) : ClapTrap(Name)
{
    this->HitPoints = 100;
    this->AttackDamage = 20;
    this->EnergytPoints = 50;
    std::cout << "ScarvTrap " << Name << " is initalized" << std::endl;
}

ScarvTrap::~ScarvTrap()
{
    std::cout << "ScarvTrap " << " is destroyed" << std::endl;
}

void ScarvTrap::guardGate()
{
    std::cout << "ScarvTrap is now in Gate Keeper Mode" << std::endl;
}

void ScarvTrap::attack(const std::string& target)
{
    if (HitPoints && EnergytPoints)
        std::cout << "ScarvTrap :) " << Name << " attacks " << target << ", causing " << AttackDamage << "pts of damage!" << std::endl;
    else
        std::cout << "Failed to attack" << std::endl;
}