/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:35:45 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/09 18:01:44 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

int Fixed::toInt(void) const
{
    return (static_cast<int>(fixed_point >> frac_bits));
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(fixed_point) / (1 << frac_bits));
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

Fixed    &Fixed::operator++(void) //++i
{
    ++this->fixed_point;
    return (*this);
}

Fixed    &Fixed::operator--(void) //--i
{
    --this->fixed_point;
    return (*this);
}

Fixed   &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.fixed_point > b.fixed_point)
        return ((Fixed &)b);
    return ((Fixed &)a);
}

Fixed   &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.fixed_point < b.fixed_point)
        return ((Fixed &)b);
    return ((Fixed &)a);
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.fixed_point > b.fixed_point)
        return (b);
    return (a);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.fixed_point < b.fixed_point)
        return (b);
    return (a);
}

Fixed    Fixed::operator++(int) //i++
{
    Fixed tmp(*this);
    tmp.fixed_point = this->fixed_point++;
    return (tmp);
}

Fixed    Fixed::operator--(int) //i--
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
    fixed_point = static_cast<int>(other_int << frac_bits);
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float other_f)
{
    fixed_point = std::roundf(other_f * (1 << frac_bits)); 
}

Fixed &Fixed::operator=(const Fixed &src)
{
    if (this != &src)
        this->fixed_point = src.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}