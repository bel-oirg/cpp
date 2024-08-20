/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:02:22 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/07 16:13:34 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void    HumanB::attack(void)
{
    if (w)
        std::cout << name << " attacks with their " << w->getType() << std::endl;
    else
        std::cout << name << " attacks with their hands" << std::endl;
}

void    HumanB::setWeapon(Weapon &new_w)
{
    w = &new_w;
}

HumanB::HumanB(std::string name) : name(name), w(NULL)
{
    std::cout << "HumanB is alive" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB is destroyed" << std::endl;
}
