/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:02:14 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/07 14:19:36 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void    Weapon::setType(std::string new_type)
{
    type = new_type;
}

const std::string&    Weapon::getType()
{
    return (type);
}

Weapon::Weapon(std::string type) : type(type) {}
