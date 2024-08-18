/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:38:29 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/15 06:52:06 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void f() { system("leaks Animal"); }

int main()
{
    // atexit(f);
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound!
    j->makeSound();
    // meta->makeSound();
    // delete meta;
    // delete i;
    delete j;

    const WrongAnimal* s = new WrongCat();

    std::cout << s->getType() << std::endl;
    s->makeSound();
    delete s;

    // const WrongAnimal* metad = new WrongCat();
    // metad->makeSound();
    // delete metad;
    return 0;
}