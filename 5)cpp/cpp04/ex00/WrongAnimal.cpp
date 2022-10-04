/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:49:17 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/19 17:49:19 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & fixed)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = fixed;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & fixed)
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return (*this);
	this->_type = fixed.getType();
	return (*this);
}

std::string WrongAnimal::getType( void ) const
{
	return (this->_type);
}

void	WrongAnimal::setType( const std::string type )
{
	this->_type = type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "* Trying to make a sound *" << std::endl;
}
