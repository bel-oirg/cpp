/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:53:43 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/17 18:31:20 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
{
    index = -1;
    f_name = "";
    l_name = "";
    n_name = "";
    phone = "";
    secret = "";
};

// Contact::~Contact() {}

str get_field(str field)
{
    str buffer;

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
    } while (buffer.empty());

    if (buffer.length() >= MAX_LEN) {
        buffer.replace(MAX_LEN, std::string::npos, 1, '.');
    }
    return (buffer);
}

void    Contact::set_data(int index)
{
    f_name = get_field("first name");
    l_name = get_field("last name");
    n_name = get_field("nick name");
    phone = get_field("phone number");
    secret = get_field("darkest secret");

    this->index = index;
}

void    Contact::get_data()
{
    std::cout << "|  " << index << "|  " << f_name << "|  " << l_name << "|  " << n_name << "|" << std::endl;
}

void    PhoneBook::add_user(int index)
{
    cts[index].set_data(index);
}

int PhoneBook::get_val(std::string s_num)
{
    int sign;
    int num;
    int i;

    sign = 1;
    num = 0;
    i = 0;
    while (s_num[i] == ' ' || s_num[i] == '\t')
        i++;
    while (s_num[i] == '-' || s_num[i] == '+')
        if (s_num[i++] == '-')
            sign *= -1;
    while (s_num[i] >= '0' && s_num[i] <= '9')
    {
        num = num * 10 + (s_num[i] - '0');
        if (num >= MAX_CONTACT)
            return (-1);
        i++;
    }
    if (i < (int)s_num.length() || sign * num < 0)
        return (-1);
    return (num);
}

void    PhoneBook::search_user(int index)
{
    int counter;
    int number;
    str s_num;

    counter = -1;
    while(++counter <= index)
        cts[counter].get_data();
    s_num = get_field("index");
    number = get_val(s_num);
    if (number >= 0 && number <= index)
        cts[number].get_data();
    else
        std::cout << "You Entered an Incorrect Value" << std::endl;
}

int main()
{
    PhoneBook booking;
    int index;
    int over;
    str cmd;

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
                std::cout << "You Have no Contact" << std::endl;
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
