/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:02:23 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/17 13:13:31 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	public:
		//	Constructors					//
		Fixed(void);
		Fixed(const int i);
		Fixed(const float i);
		Fixed(Fixed const & fixed);
		~Fixed(void);

		//	Assignment operator				//
		Fixed &	operator=(Fixed const & other);
		//	Comparison operators			//
		bool 	operator>(Fixed const & other) const;
		bool 	operator<(Fixed const & other) const;
		bool 	operator>=(Fixed const & other) const;
		bool 	operator<=(Fixed const & other) const;
		bool 	operator==(Fixed const & other) const;
		bool 	operator!=(Fixed const & other) const;
		//	Arithmetic operators			//
		Fixed 	operator+(Fixed const & other) const;
		Fixed 	operator-(Fixed const & other) const;
		Fixed 	operator*(Fixed const & other) const;
		Fixed 	operator/(Fixed const & other) const;
		//	Increment/decrement  operators	//
		Fixed &	operator++(void);
		Fixed &	operator--(void);
		Fixed 	operator++(int);
		Fixed 	operator--(int);

		//	Class member functions			//
		static Fixed &	min(Fixed & f1, Fixed & f2);
		static const Fixed &	min(Fixed const & f1, Fixed const & f2);
		static Fixed &	max(Fixed & f1, Fixed & f2);
		static const Fixed &	max(Fixed const & f1, Fixed const & f2);

		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_rawbits;
		static	const int	_point_pos;

};

//	Overloaded insertion operator			//
std::ostream &	operator<<(std::ostream & o, Fixed const & other);

#endif