/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 06:33:11 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/15 06:42:12 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "The WrongCat woke up :)" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cpy)
{
    *this = cpy;
}

WrongCat &WrongCat::operator=(const WrongCat &cpy)
{
    if (this != &cpy)
        this->type = cpy.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "An Animal is dead" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "The Cat is Meowing" << std::endl;
}