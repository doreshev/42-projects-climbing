/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:06:17 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/14 18:47:50 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
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

void	Zombie::setname(std::string name)
{
	this->_name = name;
	return ;
}
