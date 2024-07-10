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

int Fixed::toInt(void) const
{
    return ((int)(fixed_point >> frac_bits));
}

float Fixed::toFloat(void) const
{
    return ((float)(((float)fixed_point) / (1 << frac_bits)));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp)
{
    os << fp.toFloat();
    return os;
}

Fixed    Fixed::operator+(const Fixed &other)
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed    Fixed::operator-(const Fixed &other)
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed    Fixed::operator*(const Fixed &other)
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed    Fixed::operator/(const Fixed &other)
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed    Fixed::operator++(void) //no ref
{
    ++this->fixed_point;
    return (*this);
}

Fixed    Fixed::operator--(void)
{
    --this->fixed_point;
    return (*this);
}

Fixed   &Fixed::min(const Fixed &a, const Fixed &b)
{
    if ((Fixed &)a > b)
        return ((Fixed &)b);
    return ((Fixed &)a);
}

Fixed   &Fixed::max(const Fixed &a, const Fixed &b)
{
    if ((Fixed &)a < b)
        return ((Fixed &)b);
    return ((Fixed &)a);
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    if ((Fixed &)a > b)
        return ((Fixed &)b);
    return ((Fixed &)a);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    if ((Fixed &)a < b)
        return ((Fixed &)b);
    return ((Fixed &)a);
}

Fixed    Fixed::operator++(int) //no ref
{
    Fixed tmp(*this);
    tmp.fixed_point = this->fixed_point++;
    return (tmp);
}

Fixed    Fixed::operator--(int)
{
    Fixed tmp(*this);
    tmp.fixed_point = this->fixed_point--;
    return (tmp);
}

bool    Fixed::operator>(const Fixed &other)
{
    return (this->fixed_point > other.fixed_point);
}

bool    Fixed::operator>=(const Fixed &other)
{
    return (this->fixed_point >= other.fixed_point);
}

bool    Fixed::operator<(const Fixed &other)
{
    return (this->fixed_point < other.fixed_point);
}

bool    Fixed::operator<=(const Fixed &other)
{
    return (this->fixed_point <= other.fixed_point);
}

bool    Fixed::operator==(const Fixed &other)
{
    return (this->fixed_point == other.fixed_point);
}

bool    Fixed::operator!=(const Fixed &other)
{
    return (this->fixed_point != other.fixed_point);
}

int    Fixed::getRawBits() const
{
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
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    *this = src;
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int other_int)
{
    fixed_point = (int)(other_int << frac_bits);
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float other_f)
{
    fixed_point = roundf(other_f * (1 << frac_bits)); 
    // std::cout << "Float constructor called" << std::endl;

}

Fixed &Fixed::operator=(const Fixed &src)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->fixed_point = src.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}