/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 03:40:42 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/15 03:52:15 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    public:
    Cat();
    Cat(const Cat& cpy);
    Cat &operator=(const Cat& cpy);
    ~Cat();
    virtual void makeSound(void) const;
};
