/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:01:48 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/13 04:22:02 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
    FragTrap();
    FragTrap(std::string Name);
    FragTrap(const FragTrap &cpy);
    FragTrap &operator=(const FragTrap &eq);
    ~FragTrap();

    void highFivesGuys();
};

#endif