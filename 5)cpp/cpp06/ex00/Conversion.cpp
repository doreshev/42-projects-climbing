/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:57:55 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/20 11:28:57 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(void) : _value("default"), _type(STRING)
{
	// std::cout << "Conversion Default Constructor called" << std::endl;
}

Conversion::Conversion(char* value) : _value(static_cast<std::string>(value)), _type(STRING)
{
	// std::cout << "Conversion Constructor called" << std::endl;
	this->setType();
}

Conversion::~Conversion(void)
{
	// std::cout << "Conversion Destructor called" << std::endl;
}

Conversion::Conversion(const Conversion & other)
{
	// std::cout << "Conversion Copy constructor called" << std::endl;
	*this = other;
}

Conversion & Conversion::operator=(const Conversion & other)
{
	// std::cout << "Conversion Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_value = other.getValue();
	this->_type = other.getType();
	return (*this);
}

char	Conversion::getChar( void ) const
{
	int			i;

	switch (this->getType())
	{
		case STRING:
			throw ConversionImpossible();
		case CHAR:
			i = static_cast<int>(this->getValue()[0]);
			break;
		default:
			try
			{
				i = std::stoi(this->getValue());
			}
			catch(const std::exception& e)
			{
				throw ConversionImpossible();
			}
	}
	if (i < 32 || i == 127)
		throw CharNonDisplayable();
	else if (i > 127)
		throw ConversionImpossible();
	return (static_cast<char>(i));
}

int	Conversion::getInt( void ) const
{
	int	i;

	switch (this->getType())
	{
		case STRING:
			throw ConversionImpossible();
		case CHAR:
			i = static_cast<int>(this->getValue()[0]);
			break;
		default:
			try
			{
				i = std::stoi(this->getValue());
			}
			catch(const std::exception& e)
			{
				throw ConversionImpossible();
			}
	}
	return (i);
}

float	Conversion::getFloat( void ) const
{
	float f;

	switch (this->getType())
	{
		case STRING:
			throw ConversionImpossible();
		case CHAR:
			f = static_cast<float>(this->getValue()[0]);
			break;
		default:
			try
			{
				f = std::stof(this->getValue());
			}
			catch(const std::exception& e)
			{
				throw ConversionImpossible();
			}
	}
	return (f);
}

double	Conversion::getDouble( void ) const
{
	double d;

	switch (this->getType())
	{
		case STRING:
			throw ConversionImpossible();
		case CHAR:
			d = static_cast<float>(this->getValue()[0]);
			break;
		default:
			try
			{
				d = std::stod(this->getValue());
			}
			catch(const std::exception& e)
			{
				throw ConversionImpossible();
			}
	}
	return (d);
}

bool	Conversion::printNan( void ) const
{
	if (this->getValue() == "nan" || this->getValue() == "+inf" || this->getValue() == "-inf")
	{
		std::cout << "char: impossible\n"
				<< "int: impossible\n"
				<< "float: " << this->getValue() << "f\n" 
				<< "double: " << this->getValue() << std::endl;
	}
	else if (this->getValue() == "nanf" || this->getValue() == "+inff" || this->getValue() == "-inff")
	{
		std::cout << "char: impossible\n"
				<< "int: impossible\n"
				<< "float: " << this->getValue() << '\n'
				<< "double: " << this->getValue().substr(0, this->getValue().length() - 1) << std::endl;
	}
	else
		return(false);
	return(true);
}

void	Conversion::setType(void)
{
	int	i = 0;

	if (this->getValue().length() <= 1)
	{
		this->_type = INT;
		if (isdigit(this->getValue()[0]) == 0)
			this->_type = CHAR;
		return ;
	}
	if (this->getValue()[i] == '-' || this->getValue()[i] == '+')
		i++;
	while (this->getValue()[i] && isdigit(this->getValue()[i]) != 0)
		i++;
	if (!this->getValue()[i] || (this->getValue()[i] == 'f' && !this->getValue()[i + 1]))
		this->_type = INT;
	else if (this->getValue()[i] == '.')
	{
		i++;
		while (this->getValue()[i] && this->getValue()[i] == '0')
			i++;
		if (!this->getValue()[i] || (this->getValue()[i] == 'f' && !this->getValue()[i + 1]))
		{
			this->_type = INT;
			return ;
		}
		while (this->getValue()[i] && isdigit(this->getValue()[i]) != 0)
			i++;
		if (!this->getValue()[i] || (this->getValue()[i] == 'f' && !this->getValue()[i + 1]))
			this->_type = DOUBLE;
	}
}

std::string	Conversion::getValue( void ) const
{
	return (this->_value);
}

int	Conversion::getType( void ) const
{
	return (this->_type);
}
