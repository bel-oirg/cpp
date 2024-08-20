/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:09:15 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/06 18:08:57 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Harl
{
    private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    public:
    void complain(std::string level);
};

typedef void (Harl::*ft)();
/*
    creating an alias for a pointer to a member function of the class Harl
*/