/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:41:54 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/20 19:08:02 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain & other)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = other;
}

Brain & Brain::operator=(const Brain & other)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_idea[i] = other._idea[i];
	return (*this);
}

void	Brain::setIdea(std::string idea, int index)
{
	this->_idea[index] = idea;
}

const std::string & Brain::getIdea(int index) const
{
	return (this->_idea[index]);
}
