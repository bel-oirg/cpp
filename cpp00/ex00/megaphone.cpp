/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:40:48 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/17 18:27:01 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
    int index;
    int c_index;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    index = 0;
    while(argv[++index])
    {
        c_index = -1;
        /*
            std :: In C++, the Standard Library is a collection of classes and functions
        */
        while (argv[index][++c_index])
            std::cout << static_cast<char>(toupper(argv[index][c_index]));
    }
    std::cout << std::endl;
}