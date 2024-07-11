/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:58:59 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/11 12:11:44 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
    this->HitPoints = 100;
    this->AttackDamage = 30;
    this->EnergytPoints = 100;
    std::cout << "FragTrap " << Name << " is initalized" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << " is destroyed" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap XD " << Name << " high fives everybody." << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (HitPoints && EnergytPoints)
        std::cout << "FragTrap XD " << Name << " attacks " << target << ", causing " << AttackDamage << "pts of damage!" << std::endl;
    else
        std::cout << "FragTrap Failed to attack" << std::endl;
}