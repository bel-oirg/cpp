/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:23:40 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/04 13:33:00 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int is_num(std::string str)
{
    if (str.empty())
        return (0);
    for (size_t index = 0; index < str.size(); ++index)
    {
        if (!std::isdigit(str[index]))
            return (0);
    }
    return (1);
}

int is_alp(std::string str)
{
    if (str.empty())
        return (0);
    for (size_t index = 0; index < str.size(); ++index)
    {
        if (!std::isalpha(str[index]))
            return (0);
    }
    return (1);
}


static std::string get_field(std::string field)
{
    std::string buffer;
    int         err;

    do
    {
        err = 0;
        std::cout << "Please enter your " << field << ": ";
        std::getline(std::cin, buffer);

        if (std::cin.eof())
        {
            std::cin.clear();
            clearerr(stdin);
            std::cout << std::endl;
            err = 1;
        }
        else if (field == "phone number" && !is_num(buffer))
            err = 1;
        else if ((field == "first name" || field == "last name") && !is_alp(buffer))
            err = 1;
    }
    while (err);
    /*
        -> std::cin.eof() checks if the std::cin stream is in an EOF state.
        -> The clear() and clearerr(stdin) functions
        resets the state flags of the stream, including the EOF flag.
        This allows the stream to be used again without being in an error state.
    */
    if (buffer.length() >= MAX_LEN)
        buffer.replace(MAX_LEN, std::string::npos, 1, '.');
    /*
        std::string::npos This is a constant representing
        the largest possible value for size_t,
        It means the replacement should extend to the end of the string.
    */
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
    std::cout   << "|" 
                << std::setw(10) << index 
                << "|" 
                << std::setw(10) << f_name 
                << "|" 
                << std::setw(10) << l_name 
                << "|" 
                << std::setw(10) << n_name 
                << "|" 
                << std::endl;
}