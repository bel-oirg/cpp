/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:35:45 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/08 10:58:26 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

int Fixed::only_frac() const
{
    int out;

    out = (int)(fixed_point & ((1 << frac_bits) - 1));
    return (out);
}

int Fixed::toInt(void) const
{
    return ((int)(fixed_point >> frac_bits));
}

float Fixed::toFloat(void) const
{
    return ((float)((fixed_point) / (1 << frac_bits)));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp)
{
    os << fp.toInt() << "." << fp.only_frac();
    return os;
}

int    Fixed::getRawBits() const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point);
}

void    Fixed::setRawBits(int const raw)
{
    this->fixed_point = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

Fixed::Fixed()
{
    this->fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    *this = src;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int other_int)
{
    fixed_point = (int)(other_int << frac_bits);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float other_f)
{
    std::cout << "Float constructor called" << std::endl;
    fixed_point = (((other_f) * (1 << frac_bits)));

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