/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:02:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/14 18:46:34 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

std::string	HumanB::getName(void) const
{
	return(this->_name);
}

std::string	HumanB::getWeapon(void) const
{
	return(this->_weapon->getType());
}

void	HumanB::attack(void)
{
	std::cout << getName() << " attacks with their " << getWeapon() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
