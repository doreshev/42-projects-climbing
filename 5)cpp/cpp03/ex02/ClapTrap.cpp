/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:57:55 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/14 18:46:28 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hp(10), _energy(10), _dmg(0)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & fixed)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = fixed;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & fixed)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return (*this);
	this->_name = fixed.getName();
	this->_hp = fixed.getHp();
	this->_energy = fixed.getEnergy();
	this->_dmg = fixed.getDmg();
	return (*this);
}

std::string ClapTrap::getName( void ) const
{
	return (this->_name);
}

unsigned int ClapTrap::getDmg( void ) const
{
	return (this->_dmg);
}

unsigned int ClapTrap::getHp( void ) const
{
	return (this->_hp);
}

unsigned int ClapTrap::getEnergy( void ) const
{
	return (this->_energy);
}

void	ClapTrap::setName( const std::string name )
{
	this->_name = name;
}

void	ClapTrap::setHp( unsigned int i )
{
	this->_hp = i;
}

void	ClapTrap::setEnergy( unsigned int i )
{
	this->_energy = i;
}

void	ClapTrap::setDmg( unsigned int i )
{
	this->_dmg = i;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->getHp() == 0)
		std::cout << this->getName() << " don't have HP... He's literally dead!" << std::endl;
	else if (this->getEnergy() == 0)
		std::cout << this->getName() << " don't have an energy to attack!" << std::endl;
	else
	{
		std::cout << this->getName() << " attacks " << target;
		std::cout << " causing " << this->getDmg() << " points of damage!" << std::endl;
		this->_energy--;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHp() == 0)
		std::cout << this->getName() << " don't have HP... He's literally dead!" << std::endl;
	else if (this->getEnergy() == 0)
		std::cout << this->getName() << " don't have an energy to repair!" << std::endl;
	else
	{
		this->_energy--;
		this->_hp += amount;
		std::cout << this->getName() << " repairs himself " << " for an ammount of ";
		std::cout << amount << " HP!" << " Current HP is " << this->getHp() << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHp() == 0)
		std::cout << this->getName() << " don't have HP... Stop hitting dead body!" << std::endl;
	else 
	{
		if (amount >= this->getHp())
			this->_hp = 0;
		else
			this->_hp -= amount;
		std::cout << this->getName() << " got attacked " << " for an ammount of ";
		std::cout << amount << " HP!" << " Current HP is " << this->getHp() << std::endl;
	}
}
