/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:53:46 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/03 09:19:35 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>
#include "Contact.hpp"

#define MAX_CONTACT	8

class PhoneBook
{
	private:
	Contact contacts[MAX_CONTACT];

	public:
	int     get_val(std::string s_num);
	void    add_user(int index);
	void    search_user(int index);
};

/*
	A class is a user-defined data type,
	which holds its own data members and member functions,
	which can be accessed and used by creating an instance of that class.
	A C++ class is like a blueprint for an object.
*/

/*
	An object in C++ is an instance of a class that contains data
	and functions defined by the class.
*/