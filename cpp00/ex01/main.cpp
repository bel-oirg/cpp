/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 08:09:55 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/03 09:49:39 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    std::string cmd;
    PhoneBook   booking;
    int         index;
    int         over;

    over = 0;
    index = -1;
    while (1)   
    {
        std::cout << "> ";
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
        {
            if (++index >= MAX_CONTACT)
                over = 1, index %= (int)MAX_CONTACT;
            booking.add_user(index);
        }
        else if (cmd == "SEARCH")
        {
            if (index != -1)
            {
                if (over)
                    booking.search_user((int)MAX_CONTACT - 1);
                else
                    booking.search_user(index);
            }
            else
                std::cout << "You Have no Contacts" << std::endl;
        }
        else if (cmd == "EXIT")
            exit(0);
        else
        {   
            if (std::cin.eof())
            {
                std::cin.clear();
                clearerr(stdin);
                std::cout << std::endl;
            }
            std::cout << "USAGE : ADD | SEARCH | EXIT" << std::endl;
        }
    }
    return (0);
}
