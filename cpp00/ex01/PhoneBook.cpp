/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:53:43 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/04 12:58:21 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string get_num(std::string field)
{
    std::string buffer;

    do
    {
        std::cout << "Please enter your " << field << ": ";
        std::getline(std::cin, buffer);
        if (std::cin.eof())
        {
            std::cin.clear();
            clearerr(stdin);
            std::cout << std::endl;
        }
        else if (buffer.empty())
            std::cout << "The Field Cannot be Empty " << std::endl;
    }
    while (buffer.empty());
    return (buffer);
}

void    PhoneBook::add_user(int index)
{
    contacts[index].set_data(index);
}

int PhoneBook::get_val(std::string s_num)
{
    int sign;
    int num;
    int i;
    int is_d;

    sign = 1;
    num = 0;
    is_d = 0;
    i = 0;
    while (s_num[i] == ' ' || s_num[i] == '\t')
        i++;
    if (s_num[i] == '-' || s_num[i] == '+')
        if (s_num[i++] == '-')
            sign = -1;
    while (s_num[i] >= '0' && s_num[i] <= '9')
    {
        is_d = 1;
        num = num * 10 + (s_num[i] - '0');
        if (num >= MAX_CONTACT)
            return (-1);
        i++;
    }
    if (i < (int)s_num.length() || sign * num < 0 || !is_d)
        return (-1);
    return (num);
}

void    PhoneBook::search_user(int index)
{
    int         counter;
    int         number;
    std::string s_num;

    std::cout   << "-------------------📞📞📞--------------------\n"
                << "|" 
                << std::setw(10) << "INDEX" 
                << "|"
                << std::setw(10) << "FIRST NAME" 
                << "|"
                << std::setw(10) << "LAST NAME" 
                << "|" 
                << std::setw(10) << "NICK NAME" 
                << "|" 
                << std::endl;
    counter = -1;
    while(++counter <= index)
        contacts[counter].get_data();
    s_num = get_num("index");
    number = get_val(s_num);
    if (number >= 0 && number <= index)
        contacts[number].get_data();
    else
        std::cout << "You Entered an Incorrect Value" << std::endl;
}
