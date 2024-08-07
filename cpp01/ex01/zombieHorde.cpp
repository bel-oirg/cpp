/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:22:34 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/07 11:05:17 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        std::cerr << "Error" << std::endl;
        return (NULL);
    }
    Zombie* zombies = new Zombie[N];
    if (!zombies)
    {
        std::cout << "Mem allocation failed" << std::endl;
        return (NULL);
    }
    for (int i = 0 ; i < N ; i++)
        zombies[i].set_name(name);
    return (zombies);
}