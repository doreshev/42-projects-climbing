/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/17 13:38:44 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) 
{
	Point const a(0.00f, 0.0f );
	Point const b(5.05f, 0.0f );
	Point const c(0.00f, 2.0f );
	Point const p(0.08f, 1.0f );

	std::cout << "p( " << p.getX() << ", " << p.getY() << " )" << std::endl;
	std::cout << "a( " << a.getX() << ", " << a.getY() << " )" << std::endl;
	std::cout << "b( " << b.getX() << ", " << b.getY() << " )" << std::endl;
	std::cout << "c( " << c.getX() << ", " << c.getY() << " )" << std::endl;


	if (bsp(a, b, c, p) == true)
		std::cout << "Point is inside given triangle!" << std::endl;
	else
		std::cout << "Point is not inside given triangle!" << std::endl;
	return 0;
}

// int main( void ) 
// {
// 	Point const a(0.00f, 0.0f );
// 	Point const b(5.05f, 0.0f );
// 	Point const c(0.00f, 2.0f );
// 	Point const p(5.05, 0.0f );

// 	std::cout << "p( " << p.getX() << ", " << p.getY() << " )" << std::endl;
// 	std::cout << "a( " << a.getX() << ", " << a.getY() << " )" << std::endl;
// 	std::cout << "b( " << b.getX() << ", " << b.getY() << " )" << std::endl;
// 	std::cout << "c( " << c.getX() << ", " << c.getY() << " )" << std::endl;


// 	if (bsp(a, b, c, p) == true)
// 		std::cout << "Point is inside given triangle!" << std::endl;
// 	else
// 		std::cout << "Point is not inside given triangle!" << std::endl;
// 	return 0;
// }
