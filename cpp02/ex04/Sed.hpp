/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:54:03 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/07 14:30:23 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>

class Sed
{
    private:
    std::ifstream   istream;
    std::ofstream   ostream;
    std::string     find;
    std::string     replace;
    int             err;

    public:
    Sed(std::string infile,std::string find, std::string replace);
    ~Sed();
};