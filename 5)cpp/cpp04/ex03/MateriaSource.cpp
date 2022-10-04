/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:19:18 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/21 17:36:05 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	// std::cout << "MateriaSource Default Constructor called" << std::endl;
	for	(int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::~MateriaSource(void)
{
	// std::cout << "MateriaSource Destructor called" << std::endl;
	for	(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource & other)
{
	// std::cout << "MateriaSource Copy constructor called" << std::endl;
	*this = other;
}

MateriaSource & MateriaSource::operator=(const MateriaSource & other)
{
	// std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
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

void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;

	while (i < 4 && this->_inventory[i])
		i++;
	if (i < 4)
		this->_inventory[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;

	while (i < 4)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			break ;
		i++;
	}
	if (i < 4)
		return(this->_inventory[i]->clone());
	std::cout << "MateriaSource don't have a space to store " << type << std::endl;
	return (0);
}
