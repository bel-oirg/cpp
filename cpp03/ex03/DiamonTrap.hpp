/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:59:45 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/11 15:55:54 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONTRAP_H
#define DIAMONTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamonTrap:public FragTrap, public ScavTrap
{
    private:
    std::string Name;
    unsigned int HitPoints;
    unsigned int EnergytPoints;
    unsigned int AttackDamage;

    public:
    DiamonTrap(std::string Name);
    ~DiamonTrap();
    void whoAmI();
    using ScavTrap::attack;

};

#endif