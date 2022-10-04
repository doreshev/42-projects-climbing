/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/19 16:50:12 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) 
{
	DiamondTrap a("Evaluator");

	std::cout << a.getHp() << std::endl;
	std::cout << a.getDmg() << std::endl;
	std::cout << a.getEnergy() << std::endl;
	a.attack("WALL");
	a.whoAmI();
	return (0);
}
