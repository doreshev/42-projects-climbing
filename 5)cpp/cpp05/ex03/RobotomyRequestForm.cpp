/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:40:16 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/24 15:17:39 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45), _target("nothing")
{
	// std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	// std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	// std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other)
{
	// std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	*this = other;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
	// std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_target = other.getTarget();
	Form::operator=(other);
	return (*this);
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return(this->_target);
}

bool	RobotomyRequestForm:: execute(Bureaucrat const & executor) const
{
	if (this->getIssigned() == false)
		throw GradeNotSignedException();
	else if (executor.getGrade() > this->getExecute())
		throw GradeTooLowExecException();
	else
	{
		std::cout << "RobotomyRequestForm: * Some drilling noises... *   ";
		if (std::rand() % 2 == 0)
			std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
		else
			std::cout << "Lucky " << this->getTarget() << "! Robotomy was failed..." << std::endl;
	}
	return(true);
}
