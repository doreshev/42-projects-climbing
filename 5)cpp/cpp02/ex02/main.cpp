/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/17 13:40:50 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}

// int	main( void )
// {
// 	Fixed c(2.52f);
// 	Fixed d(2);

// 	std::cout << c << " + " << d << " = " << c + d << std::endl;
// 	std::cout << d << " - " << c << " = " << d - c << std::endl;

// 	std::cout << c << " * " << d << " = " << c * d << std::endl;
// 	std::cout << c << " / " << d << " = " << c / d << std::endl;

// 	std::cout << c << " >= " << d << " = " << (c >= d) << std::endl;
// 	std::cout << c << " <= " << d << " = " << (c <= d) << std::endl;
// 	return 0;
// }