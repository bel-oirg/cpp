/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 03:40:42 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/16 00:23:51 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
    Brain *brain;

    public:
    Cat();
    Cat(const Cat& cpy);
    Cat &operator=(const Cat& cpy);
    ~Cat();
    virtual void makeSound(void) const;
};
