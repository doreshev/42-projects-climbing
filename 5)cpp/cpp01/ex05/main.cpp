/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/15 11:39:40 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl		Harl;

	if (argc == 2)
		Harl.complain(argv[1]);
	else if (argc < 2)
		std::cerr << "Nothing was written!" << std::endl;
	else
		std::cerr << "Please one complain level at a time!" << std::endl;
	return (0);
}
