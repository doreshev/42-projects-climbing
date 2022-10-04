/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:06:07 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/24 15:06:48 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), _target("nothing")
{
	// std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
	// std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	// std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other)
{
	// std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	*this = other;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
	// std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_target = other.getTarget();
	Form::operator=(other);
	return (*this);
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return(this->_target);
}

bool	PresidentialPardonForm:: execute(Bureaucrat const & executor) const
{
	if (this->getIssigned() == false)
		throw GradeNotSignedException();
	else if (executor.getGrade() > this->getExecute())
		throw GradeTooLowExecException();
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
	return(true);
}
