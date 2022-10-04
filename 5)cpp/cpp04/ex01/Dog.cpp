/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:48:26 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/20 19:07:46 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog Default Constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	this->_brain->setIdea("I'm dog and I'm sooo happy to see you!", 0);
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->_brain;
}

Dog::Dog(const Dog & other)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = other;
}

Dog & Dog::operator=(const Dog & other)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other.getType();
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof! Woof! Wooof!!" << std::endl;
}

const std::string & Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}
