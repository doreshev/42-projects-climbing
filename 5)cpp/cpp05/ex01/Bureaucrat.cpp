/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:57:55 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/20 11:28:57 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
	// std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade = grade;
	// std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	// std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat & other)
{
	// std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{
	// std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_grade = other.getGrade();
	return (*this);
}

std::string Bureaucrat::getName( void ) const
{
	return (this->_name);
}

std::ostream &	operator<<(std::ostream & o, const Bureaucrat & other)
{
	o << other.getName() << ", bureaucrat grade " << other.getGrade() << ".\n";
	return (o);
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

void	Bureaucrat::incrGrade( void )
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrGrade( void )
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::signForm( Form & i )
{
	i.beSigned(*this);
	if (i.getIssigned() == true)
		std::cout << this->getName() << " signed " << i.getName() << "!\n";
	else
		std::cout << this->getName() << " couldn't sign " << i.getName() 
			<< " because grade is lesser than required for signing!"<< std::endl;
}
