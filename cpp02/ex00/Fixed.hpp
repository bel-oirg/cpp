/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:49:50 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/08 13:06:19 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
    private:
        int                 fixed_point;
        static const int    frac_bits;

    public:
        Fixed();
        Fixed(const Fixed &other); //copy constructor
        Fixed &operator=(const Fixed &src); //copy assignment operator overload
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
/*
    Using const std::string& in a function parameter
    ensures that the function does not modify the string,
    while also allowing you to pass both mutable
    and immutable strings.
    It's an efficient and flexible way to handle string inputs in C++.
*/