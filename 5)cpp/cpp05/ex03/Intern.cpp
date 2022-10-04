/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:57:34 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/24 15:26:03 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	// std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::~Intern(void)
{
	// std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern & other)
{
	// std::cout << "Intern Copy constructor called" << std::endl;
	*this = other;
}

Intern & Intern::operator=(const Intern &)
{
	// std::cout << "Intern Copy assignment operator called" << std::endl;
	return (*this);
}

Form *		Intern::makeForm(std::string form, std::string name)
{
	std::string	forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int	i = 0;

	while (i < 3 && form.compare(forms[i]))
		i++;
	switch (i)
	{
		case 3:
			throw FormNotFoundException();
		case 2:
			return (new ShrubberyCreationForm(name));
		case 1:
			return (new PresidentialPardonForm(name));
		case 0:
			return (new RobotomyRequestForm(name));
	}
	return (NULL);
}
