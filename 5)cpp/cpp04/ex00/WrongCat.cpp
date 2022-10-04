/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:49:39 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/19 17:49:40 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat Default Constructor called" << std::endl;
	this->setType("WrongCat");
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat & fixed)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = fixed;
}

WrongCat & WrongCat::operator=(const WrongCat & fixed)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return (*this);
	this->_type = fixed.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong Meow! Wrong Meow! Wrong Meow!!" << std::endl;
}
