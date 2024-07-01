#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <cstring>
#include <iostream>
#include <stdlib.h>
#define MAX_LEN 10
#define MAX_CONTACT 2
using str = std::string;

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
    ~Contact();
    void    set_data(int index);
    void    get_data();
};

class PhoneBook
{
    private:
    Contact cts[MAX_CONTACT];

    public:
    void    add_user(int index);
    void    search_user(int index);
};

#endif