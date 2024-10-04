/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:49:50 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/09 22:55:18 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
	int				fixed_point;
	static const	int frac_bits;

	public:
	Fixed();
	Fixed(const Fixed &other);
	/*
		A copy constructor is a type of constructor
		that initializes an object using another object of the same class
	*/
	Fixed(const int other_int);
	Fixed(const float other_f);
	Fixed &operator=(const Fixed &src);
	~Fixed();

	float   toFloat(void) const;
	int     toInt(void) const;

	int     getRawBits(void) const;
	void    setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fp);
/*
    operator overloading allows you to define
    custom behaviors for operators when they are
    used with class
*/
#endif
