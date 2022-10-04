/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:02:23 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/17 11:17:12 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed & fixed);
		~Fixed(void);

		Fixed & operator=(const Fixed & other);

		int	getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int					_rawbits;
		static	const int	_fractional_bits;
};

#endif