/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:48:50 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/21 10:52:36 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat Default Constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	this->_brain->setIdea("I'm cat, so world is mine!", 0);
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->_brain;
}

Cat::Cat(const Cat & other)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = other;
}

Cat & Cat::operator=(const Cat & other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other.getType();
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow! Meow! Meow!!" << std::endl;
}

const std::string & Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}
