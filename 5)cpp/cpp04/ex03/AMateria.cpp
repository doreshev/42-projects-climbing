/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:16:53 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/21 17:21:54 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	// std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	// std::cout << "AMateria Constructor called" << std::endl;
	this->_type = type;
}

AMateria::~AMateria(void)
{
	// std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria & other)
{
	// std::cout << "AMateria Copy constructor called" << std::endl;
	*this = other;
}

AMateria & AMateria::operator=(const AMateria &)
{
	// std::cout << "AMateria Copy assignment operator called" << std::endl;
	return (*this);
}

std::string const & AMateria::getType( void ) const
{
	return (this->_type);
}

void AMateria::use(ICharacter &)
{
	std::cout << "* Can't use anything *" <<std::endl;
}
