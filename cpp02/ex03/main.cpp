/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:48:04 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/09 22:14:02 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main( void )
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 32.0f);
    Point c(20.0f, 30.0f);
    Point f(9.0f, 30.0f);

    if (bsp(a, b, c, f))
        std::cout << "The point is INSIDE the triangle" << std::endl;
    else
        std::cout << "The point is OUTSIDE the triangle" << std::endl;
    return 0;
}