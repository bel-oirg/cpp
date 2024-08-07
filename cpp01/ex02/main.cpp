/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:30:47 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/07 16:31:30 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string var = "HI THIS IS BRAIN";
    std::string &stringREF = var;
    std::string *stringPTR = &var;


    std::cout << "-------VAR-------" << std::endl;
    std::cout << "Address : " << &var << std::endl;
    std::cout << "Values : " << var << std::endl;

    std::cout << "\n----StringRef----" << std::endl;
    std::cout << "Address : " << &stringREF << std::endl;
    std::cout << "Values : " << stringREF << std::endl;

    std::cout << "\n----StringPTR----" << std::endl;
    std::cout << "Address : " << stringPTR << std::endl;
    std::cout << "Values : " << *stringPTR << std::endl;
}