/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:18:42 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/24 15:03:46 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("default"), _issigned(false), _sign(1), _execute(1)
{
	// std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(std::string name, int sign, int execute)
	: _name(name), _issigned(false), _sign(sign), _execute(execute)
{
	// std::cout << "Form Constructor called" << std::endl;
	if (sign > 150 || execute > 150)
		throw GradeTooLowException();
	else if (sign < 1 || execute < 1)
		throw GradeTooHighException();
}

Form::~Form(void)
{
	// std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const Form & other)
	: _name(other.getName()), _issigned(other.getIssigned()),
	_sign(other.getSign()), _execute(other.getExecute())
{
	// std::cout << "Form Copy constructor called" << std::endl;
	*this = other;
}

Form & Form::operator=(const Form & other)
{
	// std::cout << "Form Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_issigned = other._issigned;
	return (*this);
}

std::string Form::getName( void ) const
{
	return (this->_name);
}

std::ostream &	operator<<(std::ostream & o, const Form & other)
{
	o << "Form Name: " << other.getName()
		<< "; Grade required for signing: " << other.getSign()
		<< "; Grade required for execute: " << other.getExecute()
		<< "; Grade signed: " << other.getIssigned() << ".\n";
	return (o);
}

int	Form::getSign( void ) const
{
	return (this->_sign);
}

int	Form::getExecute( void ) const
{
	return (this->_execute);
}

bool	Form::getIssigned( void ) const
{
	return (this->_issigned);
}

void	Form::beSigned(Bureaucrat & i)
{
	this->_issigned = false;
	if (i.getGrade() > this->getSign())
		throw GradeTooLowException();
	else
		this->_issigned = true;
}
