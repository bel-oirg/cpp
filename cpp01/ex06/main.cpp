/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:03:49 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/06 21:05:39 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (std::cout << "Invalid number of args" << std::endl, -1);
    Harl harled;
    harled.complain(argv[1]);
}