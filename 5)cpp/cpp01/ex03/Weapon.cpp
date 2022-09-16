/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:06:17 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/14 17:03:07 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string	type) : _type(type)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string	Weapon::getType(void) const
{
	return(this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}
