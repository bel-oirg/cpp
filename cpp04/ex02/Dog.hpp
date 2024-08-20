/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 03:40:48 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/19 15:58:29 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
    Brain *brain;

    public:
    Dog();
    Dog(const Dog& cpy);
    Dog &operator=(const Dog& cpy);
    ~Dog();
    void makeSound(void) const;
};