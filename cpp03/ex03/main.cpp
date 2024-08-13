/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:49:15 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/13 19:35:57 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamonTrap.hpp"

int main()
{
    DiamonTrap a("badre");
    // DiamonTrap b("FF");
    // b.attack("O7");
    // a.attack("EGT");
    // b.whoAmI();
    a.highFivesGuys(); //from FragTrap
    a.guardGate(); //from ScavTrap
    a.attack("target");
}