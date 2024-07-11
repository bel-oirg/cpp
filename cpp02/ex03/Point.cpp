/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:36:06 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/11 09:21:04 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0.0f), y(0.0f) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &copied) : x(copied.x), y(copied.y) {}

Point &Point::operator=(const Point &eq)
{
    if (this != &eq)
    {
        (Fixed)(this->x) = eq.getx();
        (Fixed)this->y = eq.gety();
        std::cout << eq.getx() << "GETX" << std::endl;
        std::cout << this->x << "GETX" << std::endl;
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



Point::~Point(void) {}