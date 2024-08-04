/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:23:15 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/03 10:00:40 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define MAX_LEN     9

#include <iostream>

class Contact
{
	private:
	std::string f_name;
	std::string l_name;
	std::string n_name;
	std::string secret;
	std::string phone;
	int         index;

	public:
	void    set_data(int index);
	void    get_data();
};

/*
	std::string in C++ is an object that simplifies
	the manipulation of character arrays,
	providing a wide range of functionalities
	that make working with strings more convenient
	and less error-prone compared to traditional
	C-style character arrays.	
*/