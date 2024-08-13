/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:59:33 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/13 03:25:26 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
    ScavTrap();
    ScavTrap(std::string Name);
    ScavTrap(const ScavTrap& cpy);
    ScavTrap &operator=(const ScavTrap &eq);
    ~ScavTrap();

    void guardGate();
    void attack(const std::string& target);
};

#endif