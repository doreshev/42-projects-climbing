/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:02:23 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/19 11:09:00 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class	Array {
	public:
		Array< T >( void ) : _n(0), _arr(NULL) {
			// std::cout << "Default Constructor called" << std::endl;
		}
		Array< T >( unsigned int n ) : _n(n), _arr(new T[n]) {
			// std::cout << "Constructor called" << std::endl;
		}
		Array< T >( const Array & other ) {
			*this = other;
		}
		~Array< T >( void ) {
			if (this->_n > 0)
				delete[] this->_arr;
		};

		Array & operator=(const Array & other) {
			if (this == &other)
				return (*this);
			this->_n = other.size();
			if (this->_n > 0)
				this->_arr = new T[this->_n];
			for (unsigned int i = 0; i < this->_n; i++)
				this->_arr[i] = other._arr[i];
			return (*this);
		}

		T & operator[](unsigned int num) {
			if (num >= size())
				throw std::out_of_range("Out of array range!");
			return (this->_arr[num]);
		}

		unsigned int	size(void) const {
			return (this->_n);
		}

	protected:
		unsigned int	_n;
		T*				_arr;
};

#endif