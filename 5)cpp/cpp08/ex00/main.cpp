/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/30 18:55:27 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>
#include <vector>
#include <deque>
#include <list>

int main( void ) 
{

	{
		try
		{
			std::array<int, 3>arr = {1, 2, 3};

			std::cout << std::endl << "*** Testing EasyFind on Array! ***" << std::endl;

			std::cout << *easyfind(arr, 1) << " was found in the array!" << std::endl;
			std::cout << *easyfind(arr, 3) << " was found in the array!" << std::endl;
			std::cout << *easyfind(arr, 5) << " was found in the array!" << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		try
		{
			std::vector<int> vec(3, 10);

			std::cout << std::endl <<" *** Testing EasyFind on Vector! ***" << std::endl;

			std::cout << *easyfind(vec, 10) << " was found in the vector!" << std::endl;
			std::cout << *easyfind(vec, 6) << " was found in the vector!" << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		try
		{
			std::deque<int> dq(1, 12);

			std::cout << std::endl <<" *** Testing EasyFind on Deque! ***" << std::endl;

			std::cout << *easyfind(dq, 12) << " was found in the Deque!" << std::endl;
			dq.push_front(13);
			std::cout << *easyfind(dq, 13) << " was found in the Deque!" << std::endl;
			std::cout << *easyfind(dq, 18) << " was found in the Deque!" << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	{
		try
		{
			std::list<int> l(2, 5);

			std::cout << std::endl << " *** Testing EasyFind on List! ***" << std::endl;

			std::cout << *easyfind(l, 5) << " was found in the List!" << std::endl;
			l.push_front(13);
			std::cout << *easyfind(l, 13) << " was found in the List!" << std::endl;
			std::cout << *easyfind(l, 18) << " was found in the List!" << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return (0);
}
