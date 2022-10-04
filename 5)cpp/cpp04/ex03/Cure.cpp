/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:46:24 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/21 18:32:23 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "Cure Default Constructor called" << std::endl;
}

Cure::~Cure(void)
{
	// std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure(const Cure & other)
{
	// std::cout << "Cure Copy constructor called" << std::endl;
	*this = other;
}

Cure & Cure::operator=(const Cure &)
{
	// std::cout << "Cure Copy assignment operator called" << std::endl;
	return (*this);
}

Cure* Cure::clone() const
{
	// std::cout << "Cure Clone member function was called" << std::endl;
	return(new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" <<std::endl;
}
