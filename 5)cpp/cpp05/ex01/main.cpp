/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/24 14:57:29 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	{
		try
		{
			Form		Impossible("Impossible", 0, 10);
			Form		Impossible2("Impossible2", 1, 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Bureaucrat	Student("First Year Student", 150);
			Form		Graduate("Graduation", 1, 10);

			std::cout << Graduate;
			std::cout << Student;
			Student.signForm(Graduate);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Bureaucrat	Student("Last Year Student", 1);
			Form		Graduate("Graduation", 1, 10);

			std::cout << Student;
			std::cout << Graduate;

			Student.signForm(Graduate);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Bureaucrat	Student("Last Year Student", 1);
			Form		Graduate("Graduation", 1, 10);

			std::cout << Student;
			std::cout << Graduate;

			Student.decrGrade();
			std::cout << Student;

			Student.signForm(Graduate);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
