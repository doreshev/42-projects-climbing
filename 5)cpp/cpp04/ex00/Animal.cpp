/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:57:55 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/20 11:28:57 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal & fixed)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = fixed;
}

Animal & Animal::operator=(const Animal & fixed)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return (*this);
	this->_type = fixed.getType();
	return (*this);
}

std::string Animal::getType( void ) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "* Trying to make a sound *" << std::endl;
}
