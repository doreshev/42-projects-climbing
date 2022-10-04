/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/29 19:51:01 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


int main( void )
{
	char	s[] = "hello!";
	int		i[] = {1, 2, 5};
	float	f[] = {1.5, -2.1, 4.2f};
	std::string	st[] = {"Hello, ", "Evaluator! ", "How ", "are ", "you?"};

	std::cout << "* Testing Char Array *" << std::endl;
	iter(s, std::strlen(s), fPrint);
	std::cout << std::endl;

	std::cout << std::endl << "* Testing Int Array *" << std::endl;
	iter(i, 3, fPrint);
	std::cout << std::endl;

	std::cout << std::endl << "* Testing Float Array *" << std::endl;
	iter(f, 3, fPrint);
	std::cout << std::endl;

	std::cout << std::endl << "* Testing String Array *" << std::endl;
	iter(st, 5, fPrint);
	std::cout << std::endl << std::endl;

	return 0;
}

///////////////////////////