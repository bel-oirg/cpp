/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:49:50 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/09 21:48:59 by bel-oirg         ###   ########.fr       */
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
    Fixed();
    Fixed(const Fixed &other);
    Fixed(const int other_int);
    Fixed(const float other_f);
    float toFloat(void) const;
    int toInt(void) const;
    Fixed &operator=(const Fixed &src);
    ~Fixed();

    Fixed operator+(const Fixed &other);
    Fixed operator-(const Fixed &other);
    Fixed operator/(const Fixed &other);
    Fixed operator*(const Fixed &other);

    Fixed &operator--(void);
    Fixed &operator++(void);
    Fixed operator--(int);
    Fixed operator++(int);

    static Fixed &max(const Fixed &a, const Fixed &b);
    static Fixed &min(const Fixed &a, const Fixed &b);

    static Fixed &max(Fixed &a, Fixed &b);
    static Fixed &min(Fixed &a, Fixed &b);

    bool operator>(const Fixed &other);
    bool operator<(const Fixed &other);
    bool operator>=(const Fixed &other);
    bool operator<=(const Fixed &other);
    bool operator==(const Fixed &other);
    bool operator!=(const Fixed &other);

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fp);

#endif