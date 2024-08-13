/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:58:59 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/14 00:03:09 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->HitPoints = 100;
    this->AttackDamage = 30;
    std::cout << "The default constructor of FragTrap is called" << std::endl;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
    this->HitPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap " << Name << " is initalized" << std::endl;
}

FragTrap::FragTrap(const FragTrap& cpy) : ClapTrap(cpy.Name)
{
    std::cout << "Copy constructor of FragTrap is called" << std::endl;
    this->HitPoints = cpy.HitPoints;
    this->AttackDamage = cpy.AttackDamage;
}

FragTrap &FragTrap::operator=(const FragTrap &eq)
{
    if (this != &eq)
        ClapTrap::operator=(eq);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap is destroyed" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << Name << " high fives everybody." << std::endl;
}
