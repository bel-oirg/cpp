/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:02:34 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/06 16:21:22 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
    private:
    std::string name;
    Weapon      *w;

    public:
    HumanB(std::string name);
    ~HumanB();
    void    setWeapon(Weapon &new_w);
    void    attack(void);
};
