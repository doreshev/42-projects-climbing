/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:51:52 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/17 13:18:26 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

//...............Constructors...............//

Point::Point(void)
{
	this->setX(Fixed (0));
	this->setY(Fixed (0));
}

Point::Point(const float i, const float j)
{
	this->setX(Fixed (i));
	this->setY(Fixed (j));
}

Point::~Point(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Point::Point(Point const & point)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = point;
}

Point &	Point::operator=(Point const & other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->setX(other.getX());
	this->setY(other.getY());
	return (*this);
}

Fixed	Point::getX( void ) const
{
	return (this->_x);
}

void	Point::setX( Fixed const num )
{
	const_cast<Fixed&>(this->_x) = num;
}

Fixed	Point::getY( void ) const
{
	return (this->_y);
}

void	Point::setY( Fixed const num )
{
	const_cast<Fixed&>(this->_y) = num;
}
