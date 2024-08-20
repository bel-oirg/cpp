/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:54:26 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/07 16:10:04 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string infile, std::string find, std::string replace)
	: istream(infile), find(find), replace(replace), err(0)
{
   	if (!istream.is_open())
    {
        std::cerr << "Failed to open the infile" << std::endl;
		err = 1;
		return ; 
    }
	ostream.open(infile + ".replace");
	if (!ostream.is_open())
    {
        std::cerr << "Failed to create the outfile" << std::endl;
		err = 1;
		return ;
    }
	size_t		pos;
	size_t		f_len;
	size_t		r_len;
	std::string	line;

	f_len = find.length();
	r_len = replace.length();
	while (std::getline(istream, line))
	{
		pos = 0;
		while (!find.empty() && (pos = line.find(find, pos)) != std::string::npos)
		{
			line.erase(pos, f_len);
			line.insert(pos, replace);
			pos += r_len;
		}
		ostream << line << std::endl;
	}
};

Sed::~Sed()
{
	/*
		In C++, if you attempt to close a file stream that is not open,
		nothing significant happens—it essentially does nothing. 
	*/
	istream.close();
	ostream.close();
	if (!err)
		std::cout << "[+] The replacement is done" << std::endl;
	else
		std::cerr << "[-] The replacement is failed" << std::endl;
}