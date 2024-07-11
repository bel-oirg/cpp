/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:35:59 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/11 08:18:06 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
    private:
    const Fixed x;
    const Fixed y;
    
    public:
    Point();
    Point(const float x, const float y);
    Point(const Point &copied);
    Point &operator=(const Point &eq);
    Fixed getx(void) const;
    Fixed gety(void) const;
    ~Point(void);
};

bool bsp(Point a, Point b, Point c, Point point);
float area(Point a, Point b, Point c);

#endif