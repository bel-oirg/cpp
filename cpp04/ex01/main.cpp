/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:38:29 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/17 02:42:40 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void f(){system("leaks Brain");}

int main()
{
    // atexit(f);
    // int         index = -1;
    // const       int nb = 7;
    // Animal*     animals[nb];

    Dog basic;
    {
        Dog tmp = basic;
    }
     
    // while (++index < nb/2)
    //     animals[index] = new Dog();
    // while (index < nb)
    //     animals[index++] = new Cat();
    
    // while(--index >= 0)
    //     animals[index]->makeSound();
    // while(++index < nb) nb   
    //     delete animals[index];
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // delete j;//should not create a leak
    // delete i;

    return 0;
}