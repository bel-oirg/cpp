/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:36:06 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/09 18:04:27 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0.0f), y(0.0f)
{
    // std::cout << "Point Contructor is called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &copied) : x(copied.x), y(copied.y) {}

Point &Point::operator=(const Point &eq)
{
    if (this != &eq)
    {
        (Fixed)this->x = eq.getx();
        (Fixed)this->y = eq.gety();
    }
    return (*this);
}

Fixed Point::getx(void) const
{
    return (this->x);
}

Fixed Point::gety(void) const
{
    return (this->y);
}

Point::~Point(void)
{
    // std::cout << "Point destructor is called" << std::endl;
}