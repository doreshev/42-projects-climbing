/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:57:55 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/14 18:46:28 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type) : _name(name), _weapon(type) 
{
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

std::string	HumanA::getName(void) const
{
	return(this->_name);
}

std::string	HumanA::getWeapon(void) const
{
	return(this->_weapon.getType());
}

void	HumanA::attack(void)
{
	std::cout << getName() << " attacks with their " << getWeapon() << std::endl;
}
