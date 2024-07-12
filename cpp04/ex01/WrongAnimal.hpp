/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:11:58 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/12 06:31:27 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal
{
    protected:
    std::string type;
    
    public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &cpy);
    WrongAnimal &operator=(const WrongAnimal &cpy);
    ~WrongAnimal();
    WrongAnimal(std::string name);
    void makeSound(void) const;
    std::string getType(void) const;
};

class WrongCat:public WrongAnimal
{
    public:
    WrongCat();
    void makeSound(void) const;
};

#endif
