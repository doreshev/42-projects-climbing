/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:02:23 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/15 18:40:09 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const & fixed);
		~Fixed(void);

		Fixed & operator=(Fixed const & other);

		int	getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int					_value;
		static	const int	_fractional_bits;
};

#endif