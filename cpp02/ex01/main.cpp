/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:22:28 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/07 14:51:31 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 8

int main()
{
    /*
        if you pass NULL to the name of the zombie, it will seg
        because the ft is waiting a class not a ptr
        the seg happens inside the class
    */
    Zombie* inst = zombieHorde(N, "A_name");
    if (inst != NULL)
    {
        for (int index = 0 ; index < N ; index++)
            inst[index].announce();
        delete[] inst;
    }
}