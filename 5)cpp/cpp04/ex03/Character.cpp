/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:35 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/21 19:31:47 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	// std::cout << "Character Default Constructor called" << std::endl;
	for	(int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
		_floor[i] = NULL;
	}
}

Character::Character(std::string name) : _name(name)
{
	// std::cout << "Character Default Constructor called" << std::endl;
	for	(int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}


Character::~Character(void)
{
	for	(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		if (this->_floor[i])
			delete this->_floor[i];
	}
	// std::cout << "Character Destructor called" << std::endl;
}

Character::Character(const Character & other)
{
	// std::cout << "Character Copy constructor called" << std::endl;
	*this = other;
}

Character & Character::operator=(const Character & other)
{
	// std::cout << "Character Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other.getName();
	for	(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

std::string const & Character::getName( void ) const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	int i = 0;
	int	j = 0;

	while (i < 4 && this->_inventory[i])
		i++;
	while (j < i)
	{
		if (this->_inventory[j] == m)
		{
			std::cout << this->getName() << "already have it in inventory!" << std::endl;
			return ;
		}
		j++;
	}
	if (i < 4)
		this->_inventory[i] = m;
	else
		std::cout << this->getName() << "'s inventory full!" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx > - 1 && idx < 4)
	{
		this->droponFloor(this->_inventory[idx]);
		this->_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx > - 1 && idx < 4)
	{
		if (this->_inventory[idx])
			this->_inventory[idx]->use(target);
	}
}

void	Character::droponFloor(AMateria* m)
{
	int i = 0;

	while (i < 4 && this->_inventory[i])
		i++;
	if (i < 4)
		this->_inventory[i] = m;
	else
	{
		delete this->_inventory[0];
		this->_inventory[0] = m;
	}
}
