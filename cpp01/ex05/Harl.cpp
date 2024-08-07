/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:09:21 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/06 20:54:58 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout <<  "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string all_complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    ft fts[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    Harl harled;
    int check = ( level == "DEBUG") * 1 + ( level == "INFO") * 2 + ( level == "WARNING") * 3 + ( level == "ERROR") * 4 - 1 ;
    if (check == -1)
    {
        std::cerr << "Invalid Complains" << std::endl;
        return ;
    }
    (harled.*fts[check])();
}