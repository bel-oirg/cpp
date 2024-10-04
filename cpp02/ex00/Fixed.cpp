/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:35:45 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/08 13:38:00 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac_bits = 8;
/*
    static means that the variable is shared across all instances of the class.
    There is only one copy of the variable,
    regardless of how many instances of the class are created.
*/
Fixed::Fixed()
{
    this->fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->fixed_point = src.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int    Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point);
}
/*  this
    -> The this keyword is a pointer to
    the current object inside a member function.
    -> The type of this in a member function of class T is T* (a pointer to T)
    -> In const member functions, this is a pointer to a const object,
    ensuring that the object cannot be modified.
*/
void    Fixed::setRawBits(int const raw)
{
    this->fixed_point = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

/* P1
    "Accuracy" refers to how close a measurement is to the true value,
    "precision" has to do with how much information you have about a quantity,
    
    However, integers lack precision.
    Dividing both 5 and 4 by 2, for instance, will both yield 2
    
    floats have good precision
*/

/* P2
    An IEEE-754 float (4 bytes) has three components
    seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm
    sign bit - exponent - mantissa

    there are some special values :
    0   -> 00000..
    inf -> 11111..
    NaN -> 0 11111111 10000000000000000000000

    
    number = (sign ? -1:1) * 2^(exponent) * 1.(mantissa bits)
    
    5.75 -> 101.11
    5.75 = 2^2 * 1.0111
    exponent -> 2 + 127 -> 129 -> 10000001
    mantissa -> (1.0111) -> 0111 -> 01110000000000000000000
    
    5.75 -> 0 10000001 01110000000000000000000  (32 bits)

    Examples of comparison using floats
    #define EPSILON 1.0e-7
    #define flt_equals(a, b) (fabs((a)-(b)) < EPSILON)
*/