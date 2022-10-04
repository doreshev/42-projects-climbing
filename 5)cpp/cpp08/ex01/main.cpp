/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/10/01 16:44:17 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);

		std::cout << "*** PDF Test ****" << std::endl;
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
	}
	{
		Span sp = Span(10000);
		std::vector<int> test(9997, 10);

		std::cout << "*** Test with 10000 numbers array ****" << std::endl;
		sp.addNumber(6);
		sp.addNumber(1);
		sp.addNumber(9);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
		sp.addNumber(test);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
	}
	{
		std::cout << "*** Testing exceptions! ****" << std::endl;
		std::cout << "Pushing numbers more than Span max size" << std::endl;
		std::vector<int> test(9998, 10);
		Span sp(10000);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(3);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		try
		{
			sp.addNumber(test);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		sp.addNumber(10);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
	}
	{
		Span sp2;

		std::cout << "Testing exceptions with empty array!" << std::endl;
		try
		{
			sp2.addNumber(3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << sp2.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << sp2.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		Span sp3(1);

		std::cout << "Testing one number array!" << std::endl;
		sp3.addNumber(3);
		try
		{
			std::cout << sp3.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << sp3.longestSpan() << std::endl << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}		
		try
		{
			sp3.addNumber(3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}