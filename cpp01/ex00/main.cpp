/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:53:44 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/07 16:27:11 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string s_name = "first one";
    std::string h_name = "second";

    Zombie stacked(s_name);
    stacked.annouce();

    Zombie *heaped = newZombie(h_name);
    if (heaped == NULL)
        return (-1);
    heaped->annouce();
    delete heaped;
}

/*
    static method can be called without having an object
*/