/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:33:18 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/19 17:09:37 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Constructor called" << std::endl;
	this->_name = name;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap & other) : ClapTrap(other)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap & other)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My DiamondTrap name is " << this->getName() << std::endl;
	std::cout << "My ClapTrap name is " << this->ClapTrap::getName() << std::endl;
}

std::string DiamondTrap::getName( void ) const
{
	return (this->_name);
}
