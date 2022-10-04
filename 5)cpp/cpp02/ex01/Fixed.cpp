/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:57:55 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/14 18:46:28 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_point_pos = 8;

//		Constructors	// 

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawbits = 0;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawbits = (i << _point_pos);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawbits = roundf(f * (1 << this->_point_pos));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed & fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

//......................//

//	Operators Overload	//

Fixed &	Fixed::operator=(const Fixed & fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return (*this);
	this->_rawbits = fixed.getRawBits();
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, const Fixed & other)
{
	o << other.toFloat();
	return o;
}

//......................//

//Class member functions//

int		Fixed::getRawBits( void ) const
{
	return (this->_rawbits);
}

void	Fixed::setRawBits( int const raw )
{
	this->_rawbits = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_rawbits) / (1 << _point_pos));
}

int		Fixed::toInt( void ) const
{
	return (this->_rawbits >> _point_pos);
}

//......................//