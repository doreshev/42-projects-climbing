/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:45:24 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/19 17:09:26 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	this->setEnergy(50);
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	this->setHp(100);
	this->setEnergy(50);
	this->setDmg(20);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getHp() == 0)
		std::cout << "ScavTrap " << this->getName() << " don't have HP... He's literally dead!" << std::endl;
	else if (this->getEnergy() == 0)
		std::cout << "ScavTrap " << this->getName() << " don't have an energy to attack!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->getName() << " perfoming mighty attack on " << target;
		std::cout << " and causing " << this->getDmg() << " points of damage!!!!" << std::endl;
		this->setEnergy(this->getEnergy() - 1);
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
}
