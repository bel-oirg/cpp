/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:02:25 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/06 22:58:29 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void    HumanA::attack(void)
{
    std::cout << name << " attacks with their " << w.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &w_type) : name(name), w(w_type)
{
    std::cout << "HumanA is alive" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA is dead" << std::endl;
}
