/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:02:23 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/16 13:10:36 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	public:
		Fixed(void);
		Fixed(const int i);
		Fixed(const float i);
		Fixed(Fixed const & fixed);
		~Fixed(void);

		Fixed &	operator=(Fixed const & other);

		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;

	private:
		void	setRawBits( int const raw );
		int					_rawbits;
		static	const int	_point_pos;

};

std::ostream &	operator<<(std::ostream & o, Fixed const & other);

#endif