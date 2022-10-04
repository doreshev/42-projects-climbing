/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:39:38 by doreshev          #+#    #+#             */
/*   Updated: 2022/10/03 15:44:20 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : _n(0)
{
	// std::cout << "Default Constructor called" << std::endl;
}

Span::Span( unsigned int n ) : _n(n)
{
	// std::cout << "Constructor called" << std::endl;
	this->_arr.reserve(n);
}

Span::Span( const Span & other )
{
	*this = other;
}

Span::~Span( void )
{
	// std::cout << "Destructor called" << std::endl;
}

Span & Span::operator=(const Span & other) 
{
	if (this == &other)
		return (*this);
	this->_n = other._n;
	this->_arr = other._arr;
	return (*this);
}

void	Span::addNumber(int num)
{
	if (this->_arr.size() >= this->_n)
		throw std::out_of_range("Not enough space!");

	this->_arr.push_back(num);
}

void	Span::addNumber(std::vector<int> vector)
{
	if (this->_n - this->_arr.size() < vector.size())
		throw std::out_of_range("Not enough space!");

	this->_arr.insert( this->_arr.end(), vector.begin(), vector.end() );
}

int	Span::shortestSpan(void) 
{
	std::vector<int>::iterator	it1;
	std::vector<int>::iterator	it2;
	int							res;

	if (this->_arr.size() == 0)
		throw std::length_error("No numbers was found!");
	else if (this->_arr.size() == 1)
		throw std::length_error("Only one number is in array!");

	std::sort(this->_arr.begin(), this->_arr.end());
	it1 = this->_arr.begin();
	it2 = it1 + 1;
	for (res = *it2 - *it1; it2 != this->_arr.end(); it1++, it2++)
		if (*it2 - *it1 < res)
			res = *it2 - *it1;
	return (res);
}

int	Span::longestSpan(void)
{
	if (this->_arr.size() == 0)
		throw std::length_error("No numbers was found!");
	else if (this->_arr.size() == 1)
		throw std::length_error("Only one number is in array!");

	std::sort(this->_arr.begin(), this->_arr.end());
	return (this->_arr.back() - this->_arr.front());
}
