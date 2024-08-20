/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:38:29 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/20 09:31:38 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// void f() { system("leaks Animal"); }

int main()
{
    // atexit(f);
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wr = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    wr->makeSound();
    {
        std::cout << "*******************" << std::endl;
        Dog tst = *(Dog *)j;
        std::cout << tst.getType() << " " << std::endl;
        tst.makeSound();
        std::cout << "*******************" << std::endl;
    }
    delete meta;
    delete i;
    delete j;
    delete wr;

    return 0;
}