/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/10/03 13:30:37 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
int main()
{
	{
		std::cout << "\n*** Testing iterators! ***\n" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Pushing 5, 17" << std::endl;
		std::cout << "On top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "\nRemoving top number" << std::endl;
		std::cout << "Stack size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << "\nPushing back 3, 5, 737, 0" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "\nPrinting our stack using iterators!" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n*** Testing reverse iterators! ***\n" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Pushing 5, 17" << std::endl;
		std::cout << "On top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "\nRemoving top number" << std::endl;
		std::cout << "Stack size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << "\nPushing back 3, 5, 737, 0" << std::endl;
		MutantStack<int>::reverse_iterator it = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack.rend();
		++it;
		--it;
		std::cout << "\nPrinting our stack using reverse iterators!" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		MutantStack<int> s(mstack);
		std::cout << "\n*** Testing copying constructor ***\n" << std::endl;
		std::cout << "\nPrinting copied stack using reverse iterators!" << std::endl;
		MutantStack<int>::reverse_iterator it2 = s.rbegin();
		MutantStack<int>::reverse_iterator ite2 = s.rend();
		++it2;
		--it2;
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
		MutantStack<int> s2 = s;
		std::cout << "\n*** Testing '=' operator ***\n" << std::endl;
		std::cout << "\nPrinting copied stack using reverse iterators!" << std::endl;
		MutantStack<int>::reverse_iterator it3 = s2.rbegin();
		MutantStack<int>::reverse_iterator ite3 = s2.rend();
		++it3;
		--it3;
		while (it3 != ite3)
		{
			std::cout << *it3 << std::endl;
			++it3;
		}
	}
	return 0;
}