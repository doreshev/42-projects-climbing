/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:06:17 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/14 18:49:08 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string	name) : _name(name)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << Zombie::getname() << ": Agaiiiinnnn deaaaathhhH..." << std::endl;
	return ;
}

void Zombie::announce(void)
{
	std::cout << Zombie::getname() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getname(void) const
{
	return(this->_name);
}
