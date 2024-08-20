/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:14:34 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/20 09:21:52 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
    protected:
    std::string type;
    
    public:
    Animal();
    Animal(std::string name);
    Animal(const Animal &cpy);
    Animal &operator=(const Animal &cpy);
    virtual ~Animal();
    virtual void makeSound(void) const = 0;
    std::string getType(void) const;
};

#endif