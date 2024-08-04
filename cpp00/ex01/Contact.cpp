/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:23:40 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/03 12:00:49 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static std::string get_field(std::string field)
{
    std::string buffer;

    do
    {
        std::cout << "Please enter your " << field << ": ";
        std::getline(std::cin, buffer);
        /*
            -> std::cin is an Object of class istream
            that represents the standard input stream.
            It corresponds to the C stream stdin.
            -> In C++, the cin object also allows input from the user,
            but not multi-word or multi-line input.
            That’s where the getline() function comes in handy.
        */
        if (std::cin.eof())
        {
            std::cin.clear();
            clearerr(stdin);
            std::cout << std::endl;
        }
        /*
            -> std::cin.eof() checks if the std::cin stream is in an EOF state.
            -> The clear() and clearerr(stdin) functions
            resets the state flags of the stream, including the EOF flag.
            This allows the stream to be used again without being in an error state.
        */
        else if (buffer.empty())
            std::cout << "The Field Cannot be Empty " << std::endl;
    }
    while (buffer.empty());
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
    std::cout << "|  " << index << "|  " << f_name << "|  " << l_name << "|  " << n_name << "|" << std::endl;
}