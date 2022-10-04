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

//...............Constructors...............//

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->_rawbits = 0;
}

Fixed::Fixed(const int i)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_rawbits = (i << _point_pos);
}

Fixed::Fixed(const float f)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_rawbits = roundf(f * (1 << this->_point_pos));
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}


//............Operators Overload............//

//	Assignment operator						//

Fixed &	Fixed::operator=(Fixed const & other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_rawbits = other.getRawBits();
	return (*this);
}

//	Arithmetic operators					//

Fixed 	Fixed::operator+(Fixed const & other) const
{
	Fixed temp;

	// std::cout << "Arithmetic '+' operator called" << std::endl;
	temp.setRawBits(this->getRawBits() + other.getRawBits());
	return (temp);
}

Fixed 	Fixed::operator-(Fixed const & other) const
{
	Fixed temp;

	// std::cout << "Arithmetic '-' operator called" << std::endl;
	temp.setRawBits(this->getRawBits() - other.getRawBits());
	return (temp);
}

Fixed 	Fixed::operator*(Fixed const & other) const
{
	// std::cout << "Arithmetic '*' operator called" << std::endl;
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed 	Fixed::operator/(Fixed const & other) const
{
	// std::cout << "Arithmetic '/' operator called" << std::endl;
	return (Fixed(this->toFloat() / other.toFloat()));
}

//	Comparison operators					//

bool 	Fixed::operator>(Fixed const & other) const
{
	// std::cout << "Comparison operator '>' called" << std::endl;
	return (this->getRawBits() > other.getRawBits());
}

bool 	Fixed::operator<(Fixed const & other) const
{
	// std::cout << "Comparison operator '<' called" << std::endl;
	return (this->getRawBits() < other.getRawBits());
}

bool 	Fixed::operator>=(Fixed const & other) const
{
	// std::cout << "Comparison operator '>=' called" << std::endl;
	return (this->getRawBits() >= other.getRawBits());
}

bool 	Fixed::operator<=(Fixed const & other) const
{
	// std::cout << "Comparison operator '<=' called" << std::endl;
	return (this->getRawBits() <= other.getRawBits());
}

bool 	Fixed::operator==(Fixed const & other) const
{
	// std::cout << "Comparison operator '==' called" << std::endl;
	return (this->getRawBits() == other.getRawBits());
}

bool 	Fixed::operator!=(Fixed const & other) const
{
	// std::cout << "Comparison operator '!=' called" << std::endl;
	return (this->getRawBits() != other.getRawBits());
}

//	Increment/decrement  operators			//

Fixed &	Fixed::operator++(void)
{
	// std::cout << "Pre-increment operator called" << std::endl;
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed &	Fixed::operator--(void)
{
	// std::cout << "Pre-decrement operator called" << std::endl;
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed 	Fixed::operator++(int)
{
	Fixed temp;

	// std::cout << "Post-increment operator called" << std::endl;
	temp.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed 	Fixed::operator--(int)
{
	Fixed temp;

	// std::cout << "Post-decrement operator called" << std::endl;
	temp.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() - 1);
	return (temp);
}

//	Insertion operator						//

std::ostream &	operator<<(std::ostream & o, Fixed const & other)
{
	o << other.toFloat();
	return o;
}


//..........Class member functions..........//

Fixed &	Fixed::min(Fixed & f1, Fixed & f2)
{
	if (f1 < f2)
		return(f1);
	return (f2);
}

const Fixed &	Fixed::min(Fixed const & f1, Fixed const & f2)
{
	if (static_cast<Fixed>(f1) < static_cast<Fixed>(f2))
		return (f1);
	return (f2);
}

Fixed &	Fixed::max(Fixed & f1, Fixed & f2)
{
	if (f1 > f2)
		return(f1);
	return (f2);
}

const Fixed &	Fixed::max(Fixed const & f1, Fixed const & f2)
{
	if (static_cast<Fixed>(f1) > static_cast<Fixed>(f2))
		return (f1);
	return (f2);
}

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
