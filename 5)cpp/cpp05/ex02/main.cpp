/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:43:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/24 15:18:14 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		try
		{
			Bureaucrat					Student("Last Year Student", 1);
			PresidentialPardonForm		p_form("Cat");
			RobotomyRequestForm			r_form("Dog");
			ShrubberyCreationForm		s_form("Tree");

			std::cout << p_form;
			std::cout << r_form;
			std::cout << s_form;
			std::cout << Student;

			Student.signForm(p_form);
			Student.executeForm(p_form);

			Student.signForm(r_form);
			Student.executeForm(r_form);

			Student.signForm(s_form);
			Student.executeForm(s_form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Bureaucrat					Student("Last Year Student", 1);
			PresidentialPardonForm		p_form("Cat");

			std::cout << p_form;
			std::cout << Student;

			Student.executeForm(p_form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Bureaucrat					Student("First Year Student", 150);
			RobotomyRequestForm			r_form("Dog");

			std::cout << r_form;
			std::cout << Student;

			Student.signForm(r_form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Bureaucrat					Student("Second Year Student", 72);
			RobotomyRequestForm			r_form("Dog");

			std::cout << r_form;
			std::cout << Student;

			Student.signForm(r_form);
			Student.executeForm(r_form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
