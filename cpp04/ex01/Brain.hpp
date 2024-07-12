/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:40:18 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/12 10:31:34 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain
{
    private:
    std::string ideas[100];

    public:
    Brain();
    ~Brain();
    // Brain(const Brain &cpy);
    // Brain operator(const Brain &cpy);
};

#endif