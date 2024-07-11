/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScarvTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:59:33 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/11 11:45:02 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCARVTRAP_H
#define SCARVTRAP_H

#include "ClapTrap.hpp"

class ScarvTrap:public ClapTrap
{
    public:
    ScarvTrap(std::string Name);
    ~ScarvTrap();
    void guardGate();
    void attack(const std::string& target);

};

#endif