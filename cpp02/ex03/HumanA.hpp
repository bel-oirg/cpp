/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:02:11 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/06 22:57:44 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
    private:
    std::string name;
    Weapon      &w;

    public:
    HumanA(std::string name, Weapon &w_type);
    ~HumanA();
    void    attack(void);
};
