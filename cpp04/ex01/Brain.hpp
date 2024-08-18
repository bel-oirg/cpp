/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:40:18 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/15 23:37:27 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

#define MAX_IDEAS 100

class Brain
{
    private:
    std::string ideas[MAX_IDEAS];

    public:
    Brain();
    Brain(const Brain &cpy);
    Brain &operator=(const Brain &cpy);
    ~Brain();
};

#endif