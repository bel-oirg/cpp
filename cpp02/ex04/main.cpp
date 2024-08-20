/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:31:41 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/07 14:25:51 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Invalid number of args" << std::endl;
        return 1;
    }

    Sed repl(argv[1], argv[2], argv[3]);
}