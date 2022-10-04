/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/24 15:36:13 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	{
		try
		{
			Intern	someRandomIntern;
			Form* rrf;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");

			std::cout << *rrf;

			Bureaucrat	Student("Last Year Student", 1);
			std::cout << Student;

			Student.signForm(*rrf);
			Student.executeForm(*rrf);
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Intern	someRandomIntern;
			Form* rrf;
			rrf = someRandomIntern.makeForm("presidential pardon", "Cat");

			std::cout << *rrf;

			Bureaucrat	Student("Last Year Student", 1);
			std::cout << Student;

			Student.signForm(*rrf);
			Student.executeForm(*rrf);
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Intern	someRandomIntern;
			Form* rrf;
			rrf = someRandomIntern.makeForm("shrubbery creation", "tree");

			std::cout << *rrf;

			Bureaucrat	Student("Last Year Student", 1);
			std::cout << Student;

			Student.signForm(*rrf);
			Student.executeForm(*rrf);
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Intern	someRandomIntern;
			Form* rrf;
			rrf = someRandomIntern.makeForm("Wrong form", "Bender");
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
