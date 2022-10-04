/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:57:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/24 15:25:55 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern & other);
		~Intern(void);

		Intern & operator=(const Intern &);

		class FormNotFoundException : public std::exception {
			public:
				virtual const char *what() const throw()
				{
					return ("Requested Form was not found!");
				}
		};

		Form *		makeForm(std::string form, std::string name);
};

#endif