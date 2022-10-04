/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/19 13:00:53 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) 
{
	ScavTrap a("AI");
	ScavTrap b("Human");

	a.guardGate();
	a.attack(b.getName());
	b.takeDamage(a.getDmg());
	b.beRepaired(1);

	// b.attack(a.getName());
	// a.takeDamage(b.getDmg());
	// a.beRepaired(1);

	// a.attack(b.getName());
	// b.takeDamage(a.getDmg());
	// a.attack(b.getName());
	// b.takeDamage(a.getDmg());
	// a.attack(b.getName());
	// b.takeDamage(a.getDmg());
	// a.attack(b.getName());
	// b.takeDamage(a.getDmg());
	// a.attack(b.getName());
	// a.beRepaired(1);
	// a.attack(b.getName());
	// b.takeDamage(a.getDmg());
	// a.beRepaired(1);
	// a.attack(b.getName());
	// b.takeDamage(a.getDmg());
	// a.beRepaired(1);
	return (0);
}
