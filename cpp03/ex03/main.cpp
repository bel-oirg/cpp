/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:49:15 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/14 04:59:41 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamonTrap.hpp"

int main()
{
    DiamonTrap a("badre");
    a.attack("EGT");
    a.highFivesGuys(); //from FragTrap
    a.guardGate(); //from ScavTrap
    a.attack("target");
}