/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/26 11:58:18 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (argv[1] == NULL)
			return(0);
		Conversion a(argv[1]);
		if (a.printNan() == true)
			return(0);
		try
		{
			std::cout << "char: " << a.getChar() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "int: " << a.getInt() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Float: " << a.getFloat();
			if (a.getType() == INT)
				std::cout << ".0";
			std::cout << 'f' << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "double: " << a.getDouble();
			if (a.getType() == INT)
				std::cout << ".0";
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}		
	}
	else
		std::cerr << "One argument required!" << std::endl;
	return (0);
}
