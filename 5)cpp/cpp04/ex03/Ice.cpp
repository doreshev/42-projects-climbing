/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:46:13 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/21 18:32:28 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	// std::cout << "Ice Default Constructor called" << std::endl;
}

Ice::~Ice(void)
{
	// std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice & other)
{
	// std::cout << "Ice Copy constructor called" << std::endl;
	*this = other;
}

Ice & Ice::operator=(const Ice &)
{
	// std::cout << "Ice Copy assignment operator called" << std::endl;
	return (*this);
}

Ice* Ice::clone() const
{
	// std::cout << "Ice Clone member function was called" << std::endl;
	return(new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
}
