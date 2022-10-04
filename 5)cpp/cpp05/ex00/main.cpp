/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/24 14:45:51 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	{
		try
		{
			Bureaucrat	Evaluator("Evaluator", 0);
			Bureaucrat	Student("Student", 154);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Bureaucrat	Evaluator("Evaluator", 1);
			Bureaucrat	Student("Student", 150);

			std::cout << Evaluator;
			std::cout << Student;

			Evaluator.incrGrade();
			Student.decrGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Bureaucrat	Evaluator("Evaluator", 1);
			Bureaucrat	Student("Student", 150);

			std::cout << Evaluator;
			std::cout << Student;

			Evaluator.decrGrade();
			Student.incrGrade();

			std::cout << Evaluator;
			std::cout << Student;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
