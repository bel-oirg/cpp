/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:04 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/11 11:52:42 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
    protected:
    std::string Name;
    unsigned int HitPoints;
    unsigned int EnergytPoints;
    unsigned int AttackDamage;

    public:
    //ORTHX
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &cpy);
    ClapTrap &operator=(const ClapTrap &eq);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif