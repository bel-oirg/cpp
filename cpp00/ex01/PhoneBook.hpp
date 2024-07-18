/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:53:46 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/17 11:54:00 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <string.h>

typedef std::string str;

#define MAX_LEN 10
#define MAX_CONTACT 8

class Contact
{
    private:
    str f_name;
    str l_name;
    str n_name;
    str secret;
    str phone;
    int index;

    public:
    Contact();
    // ~Contact();
    void    set_data(int index);
    str     get_field(str field);
    void    get_data();
};

class PhoneBook
{
    private:
    Contact cts[MAX_CONTACT];

    public:
    void    add_user(int index);
    int     get_val(std::string s_num);
    void    search_user(int index);
};

#endif