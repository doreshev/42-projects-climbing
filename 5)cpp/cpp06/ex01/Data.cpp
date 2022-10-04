/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:57:55 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/20 11:28:57 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : _value("default")
{
	// std::cout << "Data Default Constructor called" << std::endl;
}

Data::Data(std::string value) : _value(value)
{
	// std::cout << "Data Constructor called" << std::endl;
}

Data::~Data(void)
{
	// std::cout << "Data Destructor called" << std::endl;
}


Data::Data(const Data & other)
{
	// std::cout << "Data Copy constructor called" << std::endl;
	*this = other;
}

Data & Data::operator=(const Data & other)
{
	// std::cout << "Data Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_value = other.getValue();
	return (*this);
}

std::string	Data::getValue( void ) const
{
	return (this->_value);
}
