/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:40:48 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/08/04 09:57:10 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	int	index;
	int c_index;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	index = 0;
	while(argv[++index])
	{
		c_index = -1;
		/*
			std namespace :: the Standard Library is a collection of classes and functions
		*/
		while (argv[index][++c_index])
			std::cout << static_cast<char>(std::toupper(argv[index][c_index]));
		/*
			using static_cast<> is safer that (C cast), it perform more error checking.
		*/
	}
	std::cout << std::endl;
}

/*
	-> The inline keyword suggests to the compiler to replace a function call
			with the function's code to reduce call overhead.
	-> inlining can help to improve performance.
*/