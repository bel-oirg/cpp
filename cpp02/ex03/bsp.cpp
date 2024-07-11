/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:21:05 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/11 09:21:35 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float area(Point a, Point b, Point c)
{
    float area_sum;
    float x1 = a.getx().toFloat();
    float x2 = b.getx().toFloat();
    float x3 = c.getx().toFloat();
    float y1 = a.gety().toFloat();
    float y2 = b.gety().toFloat();
    float y3 = c.gety().toFloat();

    area_sum = ((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))/2);
    if (area_sum > 0)
        return (area_sum);
    return (-area_sum);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float area1;
    float area2;
    float area3;
    float area4;

    area1 = area(a, b, c);
    area2 = area(point, b, c);
    area3 = area(point, a, c);
    area4 = area(point, a, b);

    return (area1 == (area2 + area3 + area4)); //recheck this
}