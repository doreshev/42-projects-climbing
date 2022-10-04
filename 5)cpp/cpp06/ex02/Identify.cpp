/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:10:01 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/26 13:22:50 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base*	generate(void)
{
	int	i;

	i = std::rand() % 3 + 1;
	std::cout << "Generated case number " << i << std::endl;
	switch (i)
	{
		case 1:
			return (new A());
		case 2:
			return (new B());
	}
	return (new C());
}

void	identify(Base* p)
{
	A*	a = dynamic_cast<A *>(p);
	if (a != NULL)
		std::cout << "It's an 'A' class" << std::endl;

	B*	b = dynamic_cast<B *>(p);
	if (b != NULL)
		std::cout << "It's a 'B' class" << std::endl;

	C*	c = dynamic_cast<C *>(p);
	if (c != NULL)
		std::cout << "It's a 'C' class" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A	a = dynamic_cast<A &>(p);
		std::cout << "It's an 'A' class!" << '\n';
	}
	catch(const std::exception& e) {}

	try
	{
		B	b = dynamic_cast<B &>(p);
		std::cout << "It's a 'B' class!" << '\n';
	}
	catch(const std::exception& e) {}

	try
	{
		C	c = dynamic_cast<C &>(p);
		std::cout << "It's a 'C' class!" << '\n';
	}
	catch(const std::exception& e) {}
}
