/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/29 18:23:06 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void )
{
	{
		Array<int> a(5);
		Array<int> b;

		std::cout <<"*** Array of Ints test! ***" << std::endl;
		a[0] = 5;
		for (unsigned int i = 0; i < a.size(); i++)
		{
			std::cout << "a[" << i << "]: " << a[i] << std::endl;
		}
		try
		{
			std::cout << "a[" << 5 << "]: " << a[5] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		b = a;
		b[2] = 10;
		for (unsigned int i = 0; i < b.size(); i++)
		{
			std::cout << "b[" << i << "]: " << b[i] << std::endl;
		}
	}
	{
		Array<std::string> a(5);
		Array<std::string> b;

		std::cout <<"*** Array of Strings test! ***" << std::endl;
		a[0] = "Hello";
		for (unsigned int i = 0; i < a.size(); i++)
		{
			std::cout << "a[" << i << "]: " << a[i] << std::endl;
		}
		try
		{
			std::cout << "a[" << 5 << "]: " << a[5] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		b = a;
		b[2] = "Evaluator!";
		for (unsigned int i = 0; i < b.size(); i++)
		{
			std::cout << "b[" << i << "]: " << b[i] << std::endl;
		}
	}
	{
		Array<char> a(5);
		Array<char> b;

		std::cout <<"*** Array of chars test! ***" << std::endl;
		a[0] = 'E';
		for (unsigned int i = 0; i < a.size(); i++)
		{
			std::cout << "a[" << i << "]: " << a[i] << std::endl;
		}
		try
		{
			std::cout << "a[" << 5 << "]: " << a[5] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		b = a;
		b[2] = 'V';
		b[0] = 'A';
		for (unsigned int i = 0; i < b.size(); i++)
		{
			std::cout << "b[" << i << "]: " << b[i] << std::endl;
		}
		for (unsigned int i = 0; i < a.size(); i++)
		{
			std::cout << "a[" << i << "]: " << a[i] << std::endl;
		}
	}
	return 0;
}
