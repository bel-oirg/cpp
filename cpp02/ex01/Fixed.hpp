/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:49:50 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/08 10:24:27 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    private:
    int fixed_point;
    static const int frac_bits;

    public:
    Fixed(); //called when we initiat an instance
    Fixed(const Fixed &other); //used to copy
    Fixed(const int other_int);
    Fixed(const float other_f);
    float toFloat(void) const;
    int toInt(void) const;
    Fixed &operator=(const Fixed &src); //used to assign the objet to another
    ~Fixed(); //a destractor called when the object is destroyed
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int only_frac() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fp);

#endif