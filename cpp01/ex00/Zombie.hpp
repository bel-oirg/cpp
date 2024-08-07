/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:52:48 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/06 22:10:00 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
	private:
	std::string name;

	public:
	Zombie(std::string name);
	~Zombie();
	void    annouce(void);
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);